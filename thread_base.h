#ifndef THREAD_H
#define THREAD_H

#endif // THREAD_H

#include<map>

using namespace std;

typedef map<int, void *> thread_map;

class CThreadBase {

protected:
    int         m_counter;
    thread_map  *p_threads;
    pthread_t   p_thread;
public:
    CThreadBase();
    ~CThreadBase();
    template<class T>  int addNewThread(T *);
    int addNewThread();
    virtual void *execute()=0;
    static void *subRoutine(void *p_context);
};
