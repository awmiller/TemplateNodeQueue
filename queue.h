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
    void enqueue(T value);
    T dequeue(void);
    T front(void);
    bool isEmpty(void);
    int size(void);
    
private:

    Node<T> *beginning,*end;
    int count;
};


#include <cstdlib>

template <class T>
Queue<T>::Queue() : count(0){
  end = NULL;
  beginning = end;
}

template <class T>
Queue<T>::~Queue() {
  while(!isEmpty())
  {
    dequeue();
  }
}

template <class T>
void Queue<T>::enqueue(T value){
    
  if(this->isEmpty()){
      beginning = new Node<T>(value);
      end = beginning;
  }
  else
  {
      end->next = new Node<T>(value);
      end = end->next;
  }
  
  count ++;
}

template <class T>
T Queue<T>::dequeue(void){
  if( this->isEmpty() )
  {
      return T();
  }
  
  T ret = beginning->value;

  Node<T> *toBeDestroyed = beginning;
  
  beginning = beginning->next;

  delete(toBeDestroyed);
    
  count --;
	
  return ret;
}

template <class T>
T Queue<T>::front(void){
  if(this->isEmpty()){
      return EMPTY_VALUE;
  }
  return beginning->value;
}

template <class T>
bool Queue<T>::isEmpty(void){
  return (count == 0);
}

template <class T>
int Queue<T>::size(void){
  return count;
}



#endif	/* QUEUE_H */

