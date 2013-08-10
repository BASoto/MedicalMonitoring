//============================================================================
// Name        : MM-x86.cpp
// Author      : Bryan Soto
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Labjack.h"

/*extern "C"
{
	#include "labjackusb.h"
}*/

int main(int argc, char** argv) {
	Labjack::Labjack * lj = new Labjack::Labjack(-1);
	lj->OpenConnection();
	lj->GetVoltageFromAnalogInput(0);
	//lj->OpenConnection();
	//std::cout << "Number of devices: " << LJUSB_GetDevCount(U3_PRODUCT_ID);
}
