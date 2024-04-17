#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
#include "DoublyLinkedList.h"
using namespace std;

template <class T>
class GenQueue{
    public:
        GenQueue();
        ~GenQueue();


        void insert(T* d); // enqueue
        T* dequeue();

        unsigned int getSize();
        bool isEmpty();
        T* peek();
    
    private:
        int front;
        int rear;
        unsigned int numElements;
        DoublyLinkedList<T> *myQueue;
};

template <class T>
GenQueue<T>::GenQueue(){
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new DoublyLinkedList<T>();
}

template <class T>
GenQueue<T>::~GenQueue(){
    delete myQueue;
}


template <class T>
void GenQueue<T>::insert(T* d){
    myQueue->insertBack(d);
    numElements++;
}


template <class T>
T* GenQueue<T>::dequeue(){
    if(isEmpty()){
        throw runtime_error("Queue is empty");
    }
    T* r = myQueue->removeFront();
    numElements--;
    return r;
}

template <class T>
bool GenQueue<T>::isEmpty(){
    return (numElements == 0);
}


template <class T>
unsigned int GenQueue<T>::getSize(){
    return numElements;
}

template <class T>
T* GenQueue<T>::peek(){
    if(isEmpty()){
        throw runtime_error("Queue is empty, nothing to see");
    }
    return myQueue->getFront();
}


#endif