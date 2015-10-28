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
    Node(int value);
    Node *next;
    J value;
};

#endif	/* NODE_H */

