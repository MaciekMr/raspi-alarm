#include <stdlib.h>
#include <stdio.h>

#pragma once


class CGPIO{

private:
	bcm2835 p_bcm = {GPIO_BASE};

public:
	CGPIO();
	
	~CGPIO();
};
