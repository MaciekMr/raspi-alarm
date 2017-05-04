#include <stdlib.h>
#include <stdio.h>

enum _mode {in, out, pwm};

typedef _mode mode;

class CPin {

protected:
	mode	n_mode; 
		
public:
	CPin();
	
	~CPin();
};
