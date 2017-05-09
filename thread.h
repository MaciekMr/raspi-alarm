#ifndef THREAD_H
#define THREAD_H

#endif // THREAD_H


use namespace std;

typedef map<int, void *> thread_map;

class CThread {

private:
    int         m_counter;
    thread_map  *p_threads;
public:
    CThread();
    ~CThread();
    int addNewThread(void *);
};
