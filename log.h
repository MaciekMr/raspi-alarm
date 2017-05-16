#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

typedef vector<string>  _logger;

class Log{

protected:
    static _logger  m_logger;

private:
	Log();
	~Log();
public:
    static void logger(char * log);
};
