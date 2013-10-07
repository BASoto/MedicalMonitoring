//============================================================================
// Name        : MM-x86.cpp
// Author      : Bryan Soto
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Labjack.h"
#include "DBConnector/Database.h"

/*extern "C"
{
	#include "labjackusb.h"
}*/

int main(int argc, char** argv) {
	MedMon_DB::Database * ljDB = new MedMon_DB::Database();
	Labjack::Labjack * lj = new Labjack::Labjack(320052879);
	std::string dbUrl = "localhost";
	std::string dbUsr = "root";
	std::string dbPwd = "4TheGradz";
	std::string dbNm = "TestFromApp";
	ljDB->openDBConnection(&dbUrl, &dbUsr, &dbPwd);
	ljDB->initLJTbl(&dbNm);

	//lj->OpenConnection();
	//lj->GetVoltageFromAnalogInput(0);
	//lj->OpenConnection();
	//std::cout << "Number of devices: " << LJUSB_GetDevCount(U3_PRODUCT_ID);
}
