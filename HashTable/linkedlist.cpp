#include "linkedlist.h"
#include <iostream>

/*
 * linked list implemented
 */

LinkedList::LinkedList(){
    /* Initialize the head and tail node */
    _pHead = nullptr;
    length = 0;
}

LinkedList::LinkedList(teaching_entry val)
{
    Node<teaching_entry> n;
    _pHead = &n; //create a new node and make the head point to it
    _pHead->setValue(val);
    _pHead->setNext(nullptr);
    length++; //increase length by 1
}

LinkedList::~LinkedList()
{

}
void LinkedList::add(teaching_entry val){

        Node<teaching_entry> temp;
        Node<teaching_entry> * t = &temp;
        t->setValue(val);
        t->setNext(nullptr);
        if(_pHead == nullptr){
            std::cout << "first node" << std::endl;
            _pHead = t;
            return;
        }
        Node<teaching_entry> * cur = _pHead;
            while(cur != nullptr) {
                std::cout << "third node" << std::endl;
                if(cur->getNext() == nullptr) {
                    std::cout << "second node" << std::endl;
                    cur->setNext(t);
                    return;
                }
                cur = cur->getNext();
            }

}
/*
 * takes in string
 * returns pointer to head of linked list that holds std::string if found
 * otherwise returns nullptr
 */
Node<teaching_entry> * LinkedList::find(std::string s){


    if(_pHead == nullptr){
        std::cout << "made it here" << std::endl;
        return nullptr;
    }
    else{
        Node<teaching_entry> * cur = _pHead;
         std::cout << "made it heeeeere" << std::endl;
         Node<teaching_entry> tA(cur);
         std::cout << "made it heeeeere2" << std::endl;
         Node<teaching_entry> t(&tA);




        std::cout << t.getValue().get_member() << std::endl;


         if(t.getValue().get_member().std::string::compare(s) == 0){
             std::cout << "made it heeeeere3" << std::endl;
             //return cur;
         }
    }
    return nullptr;


}

void LinkedList::traverse_and_print()
{
    Node<teaching_entry> *p = _pHead;

    /* The list is empty? */
    if (_pHead == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    std::cout << "LinkedList: " <<std::endl;
       /* A basic way of traversing a linked list */
       while (p != nullptr) { /* while there are some more nodes left */
           /* output the value */
           //cout << p->_value;
           /* The pointer moves along to the next one */
           p = p->getNext();
       }
       std::cout << std::endl;
}

