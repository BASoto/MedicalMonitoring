/*
 * Labjack.h
 *
 *  Created on: Aug 8, 2013
 *      Author: brydev
 */

#ifndef LABJACK_H_
#define LABJACK_H_

extern "C"
{
	#include "u3.h"
}

#include <string>

namespace Labjack {

class Labjack {
	public:
	    u3CalibrationInfo caliInfo;
	    long DAC1Enable, error;

	    Labjack(int deviceID);
		void OpenConnection();
		void CloseConnection(std::string * reason);
		void GetVoltageFromAnalogInput(long portNumber);
		void GetFlexIOReading(long portNumber);

	private:
		HANDLE hDevice;
		int localID;
};

} /* namespace Labjack */
#endif /* LABJACK_H_ */
