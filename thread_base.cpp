#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "thread_base.h"

int CThreadBase::m_counter = 0;

CThreadBase::CThreadBase(){

}

CThreadBase::~CThreadBase(){

    m_counter--;
    printf("thread counter=%d\n", m_counter);
}

template<class T>
int CThreadBase::addNewThread(T * t){

    return 0;
}

int CThreadBase::addNewThread(){

    //int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg);
    int res = pthread_create(&p_thread, nullptr, &CThreadBase::subRoutine, this);
    m_counter++;
    printf("create %d thread:%d id:%d \n", m_counter, res, static_cast<int>(p_thread));
    return res;
}

void *CThreadBase::execute(){

    int count = 10;
    while (count){

        printf("ThreadBase id = %d print code=%d\n", static_cast<int>(this->p_thread), count);
        sleep(1);
        count--;
    }
    return nullptr;
}

void *CThreadBase::subRoutine(void *p_context){

    //p_context - handle to object
    printf("start subroutine\n");
    return ((reinterpret_cast<CThreadBase *>(p_context))->execute());
}
