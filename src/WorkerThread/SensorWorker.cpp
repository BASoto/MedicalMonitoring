/*
 * SensorWorker.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: brydev
 */

#include "SensorWorker.h"

using namespace Labjack_Init;
namespace WorkerThread {

	void * SensorWorker::PollSensor(void * params)
	{
		WorkerArgs * args = (WorkerArgs*)params;
		int sleepPeriod = args->Conn->PollingFrequency * 1000;

		while(true)
		{
			MedMon_DB::Database * mmDB = args->LJDB;

			printf("Recording sensor data from port %u. \n", args->Conn->PortID);


			mmDB->recordSensorReading(
					args->Conn->SensorID,
					args->Conn->PortID,
					args->LJ->GetVoltageFromAnalogInput(args->Conn->PortID),
					args->dbName);

			usleep(sleepPeriod);
		}
	}

} /* namespace MedMon_DB */
