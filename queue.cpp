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
Queue::~Queue() {
  while(!isEmpty())
  {
    dequeue();
  }
}

template <class T>
void Queue::enqueue(int value){
    
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
int Queue::dequeue(void){
  if( this->isEmpty() )
  {
      return EMPTY_VALUE;
  }
  
  int ret = beginning->value;

  Node *toBeDestroyed = beginning;
  
  beginning = beginning->next;

  delete(toBeDestroyed);
    
  count --;
	
  return ret;
}

template <class T>
int Queue::front(void){
  if(this->isEmpty()){
      return EMPTY_VALUE;
  }
  return beginning->value;
}

template <class T>
bool Queue::isEmpty(void){
  return (count == 0);
}

template <class T>
int Queue::size(void){
  return count;
}

