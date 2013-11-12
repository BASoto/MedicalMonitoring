/*
 * Initializer.h
 *
 *  Created on: Sep 8, 2013
 *      Author: brydev
 */

#ifndef INITIALIZER_H_
#define INITIALIZER_H_

extern "C"{
	#include "labjackusb.h"
}

#include "Database.h"
#include <vector>

namespace Labjack_Init {

struct SensorConnection
{
	int PortID, SensorID;
	SensorConnection(int port, int sensorID)
	{
		PortID = port;
		SensorID = sensorID;
	};
};

struct SensorIdentifier
{
	int SensorID, VolatgeMin, VoltageMax, SensorInterface;
	SensorIdentifier(int id, int min, int max, int interface)
	{
		this->SensorID = id;
		this->VolatgeMin = min;
		this->VoltageMax = max;
		this->SensorInterface = interface;
	}
};

class Initializer {
	public:
		Initializer(MedMon_DB::Database * MedMonDB);
		void initMedMon(std::string * tblName);
		std::vector<SensorConnection> * getSensorConnections(MedMon_DB::Database * ljDB, int maxSensors);
	private:
		MedMon_DB::Database * MMDB;
		void initDB(MedMon_DB::Database * ljDB, std::string * tblName);
};

} /* namespace Labjack_Init */
#endif /* INITIALIZER_H_ */
