#include <stdio.h>
#include <pthread.h>

#include "thread.h"







CThread::CThread(){

}

CThread::~CThread(){

}



int CThread::addNewThread(void *){

    //int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg);
    int res = pthread_create(p_thread, NULL, &CThread::subRoutine, this);
    return res;
}

void *CThread::execute(){

    return 0;
}

void *CThread::subRoutine(void *p_context){

    //p_context - handle to object
    return (((CThread *)p_context)->execute());
}
