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

namespace MedMon_DB {

class Database {
	public:
		sql::Connection *conn;
		sql::Statement *stmt;
		sql::ResultSet *results;

		Database();

		void openDBConnection(std::string *connectionString);
		void createDB(std::string *deviceSerial);
	private:
		sql::Driver *driver;
};

} /* namespace MedMon_DB */
#endif /* DATABASE_H_ */
