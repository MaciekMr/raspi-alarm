#ifndef THREAD_H
#define THREAD_H

#endif // THREAD_H

#include "thread_base.h"

class CThread : public CThreadBase{

public:
    CThread();
    ~CThread();
    void *execute();
};
