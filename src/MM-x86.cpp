//============================================================================
// Name        : MM-x86.cpp
// Author      : Bryan Soto
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include "Utils/Utilities.h"
#include "Initialization/Initializer.h"
#include "Labjack.h"
#include "DBConnector/Database.h"

int main(int argc, char** argv) {
	const int ljSerial = 320052879;
	std::string dbUrl = "localhost";
	std::string dbUsr = "root";
	std::string dbPwd = "4TheGradz";
	std::string dbNm = "lj" + Utils::Utilities::convertInt(ljSerial);

	MedMon_DB::Database * ljDB = new MedMon_DB::Database();
	//Labjack::Labjack * lj = new Labjack::Labjack(ljSerial);

	ljDB->openDBConnection(&dbUrl, &dbUsr, &dbPwd);
	ljDB->initLJTbl(&dbNm);

	Labjack_Init::Initializer * initializer = new Labjack_Init::Initializer(ljDB);
	std::vector<Labjack_Init::SensorConnection> * sensors = initializer->getSensorConnections(ljDB, 7);

	std::cout << "End";

	/*while(true)
	{
		for(int i = 0; i < sensors->capacity(); i++)
		{
			long sensorID = (*sensors)[i].SensorID;
			double reading = lj->GetVoltageFromAnalogInput((int)sensorID);
			ljDB->recordSensorReading((int)sensorID, (*sensors)[i].PortID, (int)reading, &dbNm);

		}

		sleep(10000);
	}*/

	//lj->OpenConnection();
	//lj->GetVoltageFromAnalogInput(0);
	//lj->OpenConnection();
	//std::cout << "Number of devices: " << LJUSB_GetDevCount(U3_PRODUCT_ID);
}
