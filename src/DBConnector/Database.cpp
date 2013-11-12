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
		sql::SQLString tblName(*ljTblName);

		std::auto_ptr<sql::Statement> stmt(conn->createStatement());
		stmt->execute("CALL spNewLjDeviceTbl('" + *ljTblName + "');");
		stmt.release();
	}

	void Database::recordSensorReading(int sensorID, int portNumber, int value, std::string * dbNm)
	{
		std::string insertStmt = "INSERT INTO " + *dbNm + " (PortID, SensorID, TimeStamp, Calibration, SensorReading) " +
				"VALUES(?,?,NOW(),?,?)";

		sql::SQLString _query(insertStmt);
		conn->setSchema("medmon");
		std::auto_ptr<sql::PreparedStatement> pstmt;
		pstmt.reset(conn->prepareStatement(_query));
		pstmt->setInt(0, sensorID);
		pstmt->setInt(1, portNumber);
		pstmt->setInt(2, 0);
		pstmt->setInt(3, value);

		pstmt.reset();
	}

	void Database::executeNonQuery(const std::string * cmd)
	{
		sql::SQLString _query(*cmd);

		std::auto_ptr<sql::Statement> stmt(conn->createStatement());
		stmt->execute(_query);
		stmt.release();
	}

	std::auto_ptr<sql::ResultSet> Database::executeQuery(const std::string * cmd)
	{
		sql::SQLString _query(*cmd);
		std::auto_ptr<sql::ResultSet> res(stmt->executeQuery(_query));

		return res;
	}
} /* namespace MedMon_DB */
