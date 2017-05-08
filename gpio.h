#include <stdlib.h>
#include <stdio.h>
extern "C" {
#include "bcm_lib.h"
}

#pragma once


class CGPIO{

private:
	bcm2835 p_bcm = {GPIO_BASE,0,NULL,NULL};

public:
	CGPIO();
	
	~CGPIO();
};
