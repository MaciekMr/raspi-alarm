#ifndef THREAD_BASE_H
#define THREAD_BASE_H

#endif // THREAD_BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <list>

using namespace std;

typedef map<int, void *> thread_ident;
typedef list<thread_ident> thread_list;

class CThreadBase{

private:


public:
    CThreadBase();
    ~CThreadBase();
    void addThread(void *);
};
