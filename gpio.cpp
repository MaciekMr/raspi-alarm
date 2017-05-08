#include <stdlib.h>
#include <stdio.h>


//#include "pin.h"
#include "gpio.h"

CGPIO::CGPIO(){
	//p_bcm = NULL;
	//p_bcm = new bcm2835;
	printf("initialize bcm\n");
	p_bcm.mem_fd = 0;		
	map_peripheral(& p_bcm);
	
	
}

CGPIO::~CGPIO(){
	/*
	if(p_bcm)
		delete(p_bcm);
	*/
	unmap_peripheral(& p_bcm);
}
