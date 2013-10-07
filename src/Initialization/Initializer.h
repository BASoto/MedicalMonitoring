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

namespace Labjack_Init {


class Initializer {
	public:
		void initMedMon();
	private:
		void initDB(MedMon_DB::Database * ljDB, std::string * tblName);
};

} /* namespace Labjack_Init */
#endif /* INITIALIZER_H_ */
