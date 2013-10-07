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

	void Database::executeNonQuery(std::string * cmd)
	{
		sql::SQLString _query(*cmd);

		std::auto_ptr<sql::Statement> stmt(conn->createStatement());
		stmt->execute(_query);
		stmt.release();
	}
} /* namespace MedMon_DB */
