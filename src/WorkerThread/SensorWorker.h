/*
 * SensorWorker.h
 *
 *  Created on: Nov 30, 2013
 *      Author: brydev
 */

#ifndef SENSORWORKER_H_
#define SENSORWORKER_H_

#include "../Initialization/Initializer.h"
#include "../DBConnector/Database.h"
#include "../Labjack.h"

namespace WorkerThread {

	struct WorkerArgs{
		Labjack_Init::SensorConnection * Conn;
		Labjack::Labjack * LJ;
		MedMon_DB::Database * LJDB;
		std::string * dbName;


		WorkerArgs(Labjack_Init::SensorConnection * sensorConn, Labjack::Labjack * lj, MedMon_DB::Database * ljDB, std::string * dbNm)
		{
			Conn = sensorConn;
			LJ = lj;
			LJDB = ljDB;
			dbName = dbNm;
		}
	};

	class SensorWorker {
		public:
		static void * PollSensor(void * params);
	};

} /* namespace MedMon_DB */
#endif /* SENSORWORKER_H_ */
