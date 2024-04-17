#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "ListNode.h"
#include <stdexcept>
#include <exception>

template <class T>
class DoublyLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(T* d);
        void insertBack(T* d);
        T* removeFront();
        T* removeBack();
        int find(T* value);
        T* removeNode(T* value);
        T* removeNodeFromBack(T* value);
        bool isEmpty();
        unsigned int getSize();
        T* getFront();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    ListNode<T> *node = front;
    ListNode<T> *nodeToBeDeleted = front;

    while(node != NULL){
        nodeToBeDeleted = node->next;
        delete node;
        node = nodeToBeDeleted;
    }

    front = nullptr;
    back = nullptr;
    size = 0;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T* d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T* d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

template <class T>
T* DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("Linked list is empty");
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }else{
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T* data = temp->data;
    --size;
    delete temp;
    return data;
}

template <class T>
T* DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("Linked list is empty");
    }

    ListNode<T> *temp = back;

    if(back->prev == NULL){
        front = NULL;
    }else{
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T* data = temp->data;
    --size;
    delete temp;
    return data;
}

template <class T>
int DoublyLinkedList<T>::find(T* value){
    int pos = -1;
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if (curr->data == value){
            break;
        }
        curr = curr->next;
    }

    if (curr == NULL){
        pos = -1;
    }

    return pos;
}

template <class T>
T* DoublyLinkedList<T>::removeNode(T* value){
    if(isEmpty()){
        throw runtime_error("The list is empty");
    }

    ListNode<T> *curr = front;

    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL){
            return NULL;
        }
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }else if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }else{
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    curr->next = NULL;
    curr->prev = NULL;

    T* temp = curr->data;
    --size;
    delete curr;
    return temp;
}

template <class T>
T* DoublyLinkedList<T>::removeNodeFromBack(T* value){
    if(isEmpty()){
        throw runtime_error("The list is empty");
    }

    ListNode<T> *curr = back;

    while(curr->data != value){
        curr = curr->prev;

        if(curr == NULL){
            return NULL;
        }
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }else if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }else{
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    curr->next = NULL;
    curr->prev = NULL;

    T* temp = curr->data;
    --size;
    delete curr;
    return temp;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

template <class T>
T* DoublyLinkedList<T>::getFront(){
    T* stuff = front->data;
    return stuff;
}




#endif