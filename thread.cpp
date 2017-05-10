#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "thread.h"







CThread::CThread(){

}

CThread::~CThread(){

}



int CThread::addNewThread(void *){

    //int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg);
    int res = pthread_create(&p_thread, NULL, &CThread::subRoutine, this);
    printf("create t:%d id:%d", res, p_thread);
    return res;
}

void *CThread::execute(){

    int count = 10;
    while (count){

        printf("Thread id = %d print code=%d\n", this->p_thread, count);
        sleep(1);
        count--;
    }
    return 0;
}

void *CThread::subRoutine(void *p_context){

    //p_context - handle to object
    printf("start subroutine\n");
    return (((CThread *)p_context)->execute());
}
