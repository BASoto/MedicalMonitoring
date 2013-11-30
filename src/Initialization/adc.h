/*
 * adc.h
 *
 *  Created on: Oct 20, 2013
 *      Author: brydev
 */

#ifndef ADC_H_
#define ADC_H_

#include <vector>

namespace gpio {

class adc {
	public:
		adc(int adcCount);
		void test();
		std::vector<int>* getValuesFromADC();
		//double * getADCInputVals(double array[]);
	private:
		int adcPortCount;
};

} /* namespace MedMon_DB */
#endif /* ADC_H_ */
