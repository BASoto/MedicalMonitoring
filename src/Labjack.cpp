/*
 * Labjack.cpp
 *
 *  Created on: Aug 8, 2013
 *      Author: brydev
 */

#include "Labjack.h"
#include <stdio.h>
#include <iostream>

namespace Labjack {

		Labjack::Labjack(int deviceID)
		{
			localID = deviceID;
			DAC1Enable = 1;
		}

		void Labjack::OpenConnection()
		{
			if((hDevice = openUSBConnection(localID)) == NULL)
			{
				std::cout << "Device not found...";
				throw "A u3 with the specified device ID was not found";
			}

			if(getCalibrationInfo(hDevice, &caliInfo) < 0 )
			{
				std::string errorReason = "u3 calibration info not found...";
				this->CloseConnection(&errorReason);
			}
		}

		void Labjack::CloseConnection(std::string * reason)
		{
			closeUSBConnection(hDevice);
			std::cout << "The labjack was closed for the following reason: " << *reason;
		}

		void Labjack::GetVoltageFromAnalogInput(long portNumber)
		{
			double voltage;
			if( (error = eAIN(hDevice, &caliInfo, 1, &DAC1Enable, portNumber, 31, &voltage, 0, 0, 0, 0, 0, 0)) != 0 )
			{
			  printf("No voltage found...");
			}

			printf("Port value = %.3f\n", voltage);
		}


		void Labjack::GetFlexIOReading(long portNumber)
		{
			/*long lngState;
			    if( (error = eDI(hDevice, 1, 4, &lngState)) != 0 )
			        goto close;
			printf("FIO4 state = %ld\n", lngState);*/
		}

} /* namespace Labjack */
