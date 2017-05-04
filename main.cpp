#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bcm2835.h>
#include "bcm_lib.h"
#include "pin.h"
#include "gpio.h"


using namespace std;

int main (int n, char ** par)
{
	/*
	if(!bcm2835_init())
		return 1;
	cout << "initiated \n";	
	*/
	//CPin pin();
	
	//bcm2835 _bcm2835;
	
	//printf("before CGPIO %d \n", gpio.addr_p);
	//printf("before CGPIO %d \n", _bcm2835.addr_p);
	
	CGPIO gp;
	
	//printf("after CGPIO %d \n", gpio.addr_p);
	//printf("before CGPIO %d \n", _bcm2835.addr_p);
	
	
	
	return 0;
}
