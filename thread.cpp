#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "thread.h"

CThread::CThread(){

}

CThread::~CThread(){

    //wait until thread done

}

void * CThread::execute(){

    int count = 10;
    while (count){

        printf("Thread id = %d print code=%d\n", (int) this->p_thread, count);
        sleep(1);
        count--;
    }
    return 0;
}
