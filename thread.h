#ifndef THREAD_H
#define THREAD_H

#endif // THREAD_H

#include<map>

using namespace std;

typedef map<int, void *> thread_map;

class CThread {

private:
    int         m_counter;
    thread_map  *p_threads;
    pthread_t   p_thread;
public:
    CThread();
    ~CThread();
    int addNewThread(void *);
    void *execute();
    static void *subRoutine(void *p_context);
};
