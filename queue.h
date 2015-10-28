/* 
 * Andrew Miller
 * 915113828
 * amiller2@sfsu.edu
 * gcc version 4.9.3 (GCC)
 */

#ifndef QUEUE_H
#define	QUEUE_H
#include "node.h"

#define EMPTY_VALUE -1

template <class T>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    T dequeue(void);
    T front(void);
    bool isEmpty(void);
    int size(void);
    
private:

    Node<T> *beginning,*end;
    int count;
};

#endif	/* QUEUE_H */

