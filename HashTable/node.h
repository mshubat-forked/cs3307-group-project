#ifndef NODE
#define NODE
/*
 *This class defines a template for a binary node to be utilized in a linkedList
 * template can take on any variable type
 */
#include <iostream>

template <class E>
class Node
{
private:
    E element;
    Node * next; /* pointer to the next node */

public:
    /* Constructors with No Arguments */
    Node();
    /* Constructors with a given value */
    Node(E ele);
    /* Constructors with a given value and a link to the next node */
    Node(E ele, Node<E>* n);
    /* Constructor with a given pointer to another node */
    Node(Node<E> *n);
    /*Copy Constructor*/
    Node(Node<E>& p);

    /* Getters */
    E getValue();
    Node* getNext();
    /* Setters */
    void setValue(E ele);
    void setNext(Node * n);
    Node<E>& operator=(Node<E> &rhs); //overload '='
};




#endif // NODE

template<class E>
Node<E>::Node(){
       next = nullptr;
}
template<class E>
Node<E>::Node(E ele){
    element = ele;
    next = nullptr;
}
template<class E>
Node<E>::Node(E ele, Node<E> *n){
    element = ele;
    next = n;
}
template<class E>
Node<E>::Node(Node<E>* n){
    std::cout << "constructor called" << std::endl;
    element = n->getValue();
    std::cout << "error here?" << std::endl;
    next = n->getNext();
}

template<class E>
Node<E>::Node(Node<E>& p){

    element = (p.getValue());
    next = (p.getNext());
}
template<class E>
Node<E> & Node<E>::operator=(Node<E> &rhs){
    // Only do assignment if RHS is a different object from this.
        if (this == &rhs) {
            return *this;
        }
        element = rhs.getValue();
        next = rhs.getNext();
        return *this;

}

template<class E>
E Node<E>::getValue(){
    return element;
}
template<class E>
Node<E> * Node<E>::getNext(){
    return next;
}
template<class E>
void Node<E>::setNext(Node *n){
    next = n;
}
template<class E>
void Node<E>::setValue(E ele){
    element = ele;
}

