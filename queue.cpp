/* 
 * Andrew Miller
 * 915113828
 * amiller2@sfsu.edu
 * gcc version 4.9.3 (GCC)
 */
#include "queue.h"
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
      beginning = new Node(value);
      end = beginning;
  }
  else
  {
      end->next = new Node(value);
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
  
  int ret = beginning->value;

  Node *toBeDestroyed = beginning;
  
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

