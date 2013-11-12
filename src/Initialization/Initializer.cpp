/*
 * Initializer.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: brydev
 */

#include "Initializer.h"
#include "stdio.h"
#include "adc.h"

namespace Labjack_Init {

	Initializer::Initializer(MedMon_DB::Database * MedMonDB)
	{
		MMDB = MedMonDB;
	}

	void Initializer::initMedMon(std::string * tblName)
	{
		this->initDB(MMDB, tblName);
	}

	void Initializer::initDB(MedMon_DB::Database * ljDB, std::string * tblName)
	{
		std::string query = "CALL spNewLjDeviceTbl('" + *tblName + "');";
		ljDB->executeNonQuery(&query);
	}

	std::vector<SensorConnection> * Initializer::getSensorConnections(MedMon_DB::Database * ljDB, int maxSensors)
	{
		gpio::adc ADC(maxSensors);
		std::vector<int> * adcVals = ADC.getValuesFromADC();
		std::vector<SensorIdentifier> identities;
		std::vector<SensorConnection> * sensorConnections = new std::vector<SensorConnection>();
		std::string query = "Select SensorID, SensorVoltageIDMin, SensorVoltageIDMax, SensorInterface from sensor";
		std::auto_ptr<sql::ResultSet> results = ljDB->executeQuery(&query);

		while(results->next())
		{
			identities.push_back(SensorIdentifier(
					results->getInt(sql::SQLString("SensorID")),
					results->getInt(sql::SQLString("SensorVoltageIDMax")),
					results->getInt(sql::SQLString("SensorVoltageIDMin")),
					results->getInt(sql::SQLString("SensorInterface"))
			));
		}

		for(unsigned int i = 0; i < adcVals->capacity(); i++)
		{
			for(unsigned int j = 0; j < identities.capacity(); j++)
			{
				if(((*adcVals)[i] >= identities[j].VolatgeMin) && ((*adcVals)[i] <= identities[j].VoltageMax))
				{
					sensorConnections->push_back(
						SensorConnection(
								i,
								identities[j].SensorID
						)
					);

					printf("Sensor detected, PortID: %n, SensorID: %n", i, identities[j].SensorID);
				}
			}
		}

		delete adcVals;
		return sensorConnections;
	}
} /* namespace Labjack_Init */
