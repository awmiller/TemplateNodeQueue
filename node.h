/* 
 * Andrew Miller
 * 915113828
 * amiller2@sfsu.edu
 * gcc version 4.9.3 (GCC)
 */

#ifndef NODE_H
#define	NODE_H

template <class J>
class Node {
public:
    Node(J value);
    Node *next;
    J value;
};

template <class J>
Node<J>::Node(J value) {
  this->value = value;
}

#endif	/* NODE_H */

