#include <stdio.h>
#include <pthread.h>

#include "thread.h"







CThread::CThread(){

}

CThread::~CThread(){

}



int CThread::addNewThread(void *){

    int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg);
}

