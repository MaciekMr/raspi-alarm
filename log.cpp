#include "log.h"




Log::Log(){
	
}

Log::~Log(){
	
	m_logger.clear();
}

static void Log::logger(char * line){
	
	string str = line;
	m_logger.append(str);
}
