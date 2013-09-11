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

	void Database::openDBConnection(std::string *connectionString)
	{


	}

} /* namespace MedMon_DB */
