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
#include <pthread.h>
#include "Utils/Utilities.h"
#include "Initialization/Initializer.h"
#include "Labjack.h"
#include "DBConnector/Database.h"
#include "WorkerThread/SensorWorker.h"

int main(int argc, char** argv) {
	const int ljSerial = 320052879;
	//const int ljSerial = -1;
	std::string dbUrl = "localhost";
	std::string dbUsr = "root";
	std::string dbPwd = "4TheGradz";
	std::string dbNm = "lj" + Utils::Utilities::convertInt(ljSerial);

	MedMon_DB::Database * ljDB = new MedMon_DB::Database();
	Labjack::Labjack * lj = new Labjack::Labjack(ljSerial);

	ljDB->openDBConnection(&dbUrl, &dbUsr, &dbPwd);
	ljDB->initLJTbl(&dbNm);

	Labjack_Init::Initializer * initializer = new Labjack_Init::Initializer(ljDB);
	std::vector<Labjack_Init::SensorConnection> * sensors = initializer->getSensorConnections(ljDB, 7);

	lj->OpenConnection();
	unsigned int sensorCount = sensors->capacity();
	pthread_t sensorWorkerThreads[sensorCount];

	for(int i = 0; i < sensorCount; i++)
	{
		std::cout << "Instantiating sensor worker thread. \n";
		WorkerThread::WorkerArgs * threadArgs = new WorkerThread::WorkerArgs(&(*sensors)[i], lj, ljDB, &dbNm);
		int threadStatus = pthread_create(&sensorWorkerThreads[i], NULL, WorkerThread::SensorWorker::PollSensor, threadArgs);

		if(threadStatus)
		{
			std::cout << "An error has occurred when instantiating a thread. \n";
		}
	}

	while(true)
	{
		std::cout << "Primary process is sleeping... \n";
		sleep(100000);
	}
}
