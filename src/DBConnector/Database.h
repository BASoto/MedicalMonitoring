/*
 * Database.h
 *
 *  Created on: Sep 8, 2013
 *      Author: brydev
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace MedMon_DB {

struct SensorIdentifier
{
	int SensorID, SensorVoltageInmV;

	SensorIdentifier(int sensorID, int sensorVoltage)
	{
		SensorID = sensorID;
		SensorVoltageInmV = sensorVoltage;
	}
};

class Database {
	public:
		sql::ResultSet * results;
		sql::PreparedStatement * pstmt;
		std::auto_ptr<sql::Connection> conn;
		Database();

		void recordSensorReading(int sensorID, int portNumber, int value, std::string * dbNm);
		void openDBConnection(std::string * dbURL, std::string * user, std::string * pw);
		void executeNonQuery(const std::string * cmd);
		std::auto_ptr<sql::ResultSet> executeQuery(const std::string * cmd);
		void initLJTbl(std::string * ljTblName);
	private:
		sql::Driver *driver;
};

} /* namespace MedMon_DB */
#endif /* DATABASE_H_ */
