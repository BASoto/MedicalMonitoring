/*
 * Initializer.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: brydev
 */

#include "Initializer.h"

namespace Labjack_Init {

	void Initializer::initMedMon()
	{

	}

	void Initializer::initDB(MedMon_DB::Database * ljDB, std::string * tblName)
	{
		std::string query = "CALL spNewLjDeviceTbl('" + *tblName + "');";
		ljDB->executeNonQuery(&query);
	}

} /* namespace Labjack_Init */
