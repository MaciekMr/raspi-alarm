#include "log.h"


vector<string> Log::m_logger;

Log::Log(){
	
}

Log::~Log(){
	
	m_logger.clear();
}

void Log::logger(char * line){
	
	string str = line;
    m_logger.push_back(str);
}
