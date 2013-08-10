//============================================================================
// Name        : MM-x86.cpp
// Author      : Bryan Soto
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

extern "C"
{
	#include "labjackusb.h"
}

int main(int argc, char** argv) {
	std::cout << "Number of devices: " << LJUSB_GetDevCount(U3_PRODUCT_ID);
}
