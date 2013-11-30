/*
 * adc.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: brydev
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "adc.h"

namespace gpio {

	adc::adc(int adcCount)
	{
		adcPortCount = adcCount;
	}

	void adc::test()
	{
		  char AIN_DEV[] = "/sys/bus/iio/devices/iio\:device0/in_voltage0_raw";
		  int fd = open(AIN_DEV, O_RDONLY);

		  while (1)
		  {
		    char buffer[1024];
		    int ret = read(fd, buffer, sizeof(buffer));
		    if (ret != -1)
		    {
				buffer[ret] = '\0';
				printf("digital value: %s", buffer);
				lseek(fd, 0, 0);
				/*buffer[ret] = '\0';
				double celsius = temperature(buffer);
				double fahrenheit = CtoF(celsius);
				printf("digital value: %s  celsius: %f  fahrenheit: %f\n", buffer, celsius, fahrenheit);
				lseek(fd, 0, 0);*/
		    }
		    sleep(1);
		  }

		  close(fd);

	}

	std::vector<int> * adc::getValuesFromADC()
    {
		char AIN_DEV[] = "/sys/bus/iio/devices/iio\:device0/in_voltage0_raw";
		std::vector<int> * adcValues = new std::vector<int>();

		for(int i = 0; i <= adcPortCount; i++)
		{
			AIN_DEV[43] = '0' + i;
			int fd = open(AIN_DEV, O_RDONLY);
			char buffer[1024];
			int ret = read(fd, buffer, sizeof(buffer));
			buffer[ret] = '\0';

			if (ret != -1)
			{
				printf("ADC Port %i value: %s \n", i, buffer);
				adcValues->push_back(atoi(buffer));
				lseek(fd, 0, 0);
		    }
		}

		return adcValues;
    }
} /* namespace MedMon_DB */
