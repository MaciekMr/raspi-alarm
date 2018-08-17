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

        printf("Thread id = %d print code=%d\n", static_cast<int>(this->p_thread), count);
/* TODO:
 * Check if the connection still exist
 * *********************/
        sleep(1);
        count--;
    }
    return nullptr;
}
