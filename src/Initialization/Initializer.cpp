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
		std::string query = "SELECT SensorID, SensorVoltageIdMin_mV, SensorVoltageIdMax_mV, SensorInterface, PollingFrequency_ms FROM Sensor";

		std::auto_ptr<sql::ResultSet> results;

		try
		{
			results = ljDB->executeQuery(&query);

			while(results->next())
			{
				identities.push_back(SensorIdentifier(
						results->getInt(sql::SQLString("SensorID")),
						results->getInt(sql::SQLString("SensorVoltageIDMax_mV")),
						results->getInt(sql::SQLString("SensorVoltageIDMin_mV")),
						results->getInt(sql::SQLString("SensorInterface")),
						results->getInt(sql::SQLString("PollingFrequency_ms"))
				));

				printf("MySql Sensor Type Read: SensorID: %u, Max: %u, Min: %u, Interface: %u, Frequency: %u \n",
						results->getInt(sql::SQLString("SensorID")),
						results->getInt(sql::SQLString("SensorVoltageIdMax_mV")),
						results->getInt(sql::SQLString("SensorVoltageIdMin_mV")),
						results->getInt(sql::SQLString("SensorInterface")),
						results->getInt(sql::SQLString("PollingFrequency_ms"))
					  );
			}
		}
		catch(sql::SQLException &ex)
		{
			std::cout << "A database error has occurred: " << ex.getErrorCode() << ex.what() << "\n";
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
								identities[j].SensorID,
								identities[j].PollingFrequency
						)
					);

					printf("Sensor detected, PortID: %n, SensorID: %n \n", &i, &identities[j].SensorID);
				}
			}
		}

		/*Testing threads*/
		sensorConnections->push_back(SensorConnection(0, 0, 1000));
		sensorConnections->push_back(SensorConnection(1, 1, 10000));

		delete adcVals;
		identities.clear();
		return sensorConnections;
	}
} /* namespace Labjack_Init */
