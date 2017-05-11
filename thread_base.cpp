#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "thread_base.h"

CThreadBase::CThreadBase(){

}

CThreadBase::~CThreadBase(){

}

template<class T>
int CThreadBase::addNewThread(T * t){

    return 0;
}

int CThreadBase::addNewThread(){

    //int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg);
    int res = pthread_create(&p_thread, NULL, &CThreadBase::subRoutine, this);
    printf("create t:%d id:%d", res, (int) p_thread);
    return res;
}

void *CThreadBase::execute(){

    int count = 10;
    while (count){

        printf("ThreadBase id = %d print code=%d\n", (int) this->p_thread, count);
        sleep(1);
        count--;
    }
    return 0;
}

void *CThreadBase::subRoutine(void *p_context){

    //p_context - handle to object
    printf("start subroutine\n");
    return (((CThreadBase *)p_context)->execute());
}
