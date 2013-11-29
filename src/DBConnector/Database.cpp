/*
 * Database.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: brydev
 */

#include "Database.h"

using namespace sql;

namespace MedMon_DB {

	Database::Database()
	{
		driver = get_driver_instance();
	}

	void Database::openDBConnection(std::string * dbURL, std::string * user, std::string * pw)
	{
		sql::SQLString dbStr(*dbURL);
		sql::SQLString dbUsr(*user);
		sql::SQLString usrPw(*pw);

		conn.reset(driver->connect(dbStr, dbUsr, usrPw));
		conn->setSchema("medmon");
	}

	void Database::initLJTbl(std::string * ljTblName)
	{
		std::cout << "Initializing labjack database\n";
		std::string initTblQuery = "CALL spNewLJDeviceTbl(?)";
		sql::SQLString _query(initTblQuery);
		pstmt = conn->prepareStatement(_query);
		pstmt->setString(1, sql::SQLString(initTblQuery));
		pstmt->execute();
		delete pstmt;
	}

	void Database::recordSensorReading(int sensorID, int portNumber, int value, std::string * dbNm)
	{
		std::string insertStmt = "INSERT INTO " + *dbNm + " (PortID, SensorID, TimeStamp, Calibration, SensorReading) " +
				"VALUES(?,?,NOW(),?,?)";

		sql::SQLString _query(insertStmt);
		std::auto_ptr<sql::PreparedStatement> pstmt;
		pstmt.reset(conn->prepareStatement(_query));
		pstmt->setInt(0, sensorID);
		pstmt->setInt(1, portNumber);
		pstmt->setInt(2, 0);
		pstmt->setInt(3, value);

		pstmt.release();
	}

	void Database::executeNonQuery(const std::string * cmd)
	{
		std::cout << "Non Query called";
		sql::SQLString _query(*cmd);
		pstmt = conn->prepareStatement(_query);
		pstmt->execute();

		delete pstmt;
	}

	std::auto_ptr<sql::ResultSet> Database::executeQuery(const std::string * cmd)
	{
		sql::SQLString _query(*cmd);
		pstmt = conn->prepareStatement(_query);
		std::auto_ptr<sql::ResultSet> res(pstmt->executeQuery());
		//std::auto_ptr<sql::ResultSet> res(pstmt->executeQuery(_query));
		//stmt.release();
		delete pstmt;
		return res;
	}
} /* namespace MedMon_DB */
