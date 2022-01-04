#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <assert.h>
#include "ADT.h"
using namespace std;

template <typename T>
struct Node {
    T payload;
    Node* next;
};

// Implementation of a singly linked list
template <typename T>
class LinkedList : public ADT {
private:

    Node<T>* head;
    u_int32_t size;

public:
    //Initialize the values of head and size
    LinkedList();

    //Deallocate all existing Nodes in the linked list created using new to prevent any memory leaks
    ~LinkedList();

    //Inserts a node at head
    void InsertHead(T payload);

    //Deletes current head and makes the next node head
    T DeleteHead();

    //Inserts a new node at tail
    void InsertTail(T payload);

    //Deletes current tail and makes the previous node as tail
    T DeleteTail();

    //Inserts a node before the node at specified index (Inserts at tail if this->length() is given as index)
    void Insert(T payload, int index);

    //Deletes node at specified index
    T Delete(int index);

    //Returns the payload in the node at the specified index
    T Traverse(int index);

    //Returns index of the first node containing the specified payload_value (Returns -1 if the payload_value is not present in the linked list)
    int LinearSearch(T payload_value);

    //Prints list using cout
    void PrintList();

    //Swaps two lists (Returns 0 if successful and -1 if not)
    int Swap(LinkedList &L);

    //Deletes the entire list to prevent any memory leaks
    void DeleteList();

    //Returns the size of the linked list
    u_int32_t length();

    //Returns the type of the ADT
    string type();
};

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    this->DeleteList();
}

template <typename T>
void LinkedList<T>::InsertHead(T payload) {
    Node<T>* node = new Node<T>;
    
    node->payload = payload;
    node->next = this->head;

    this->head = node;

    size++;
}

template <typename T>
T LinkedList<T>::DeleteHead() {
    
    assert(size != 0);

    Node<T> *del = this->head;

    this->head = this->head->next;
    T ret = del->payload;

    delete del;
    this->size--;
    return ret;
}

template <typename T>
void LinkedList<T>::InsertTail(T payload) {
    Node<T>* iter = this->head;

    while(iter->next != NULL) {
        iter = iter->next;
    }

    Node<T> *node = new Node<T>;
    node->next = NULL;
    node->payload = payload;

    iter->next = node;
    this->size++;
}

template <typename T>
T LinkedList<T>::DeleteTail() {
    Node<T>* iter = this->head;

    if (this->length() == 1) {
        return this->DeleteHead();
    }

    while(iter->next->next != NULL) {
        iter = iter->next;
    }

    Node<T> *del = iter->next;
    T ret = del->payload;

    iter->next = NULL;
    this->size--;
    delete del;
    return ret;
}

template <typename T>
void LinkedList<T>::Insert(T payload, int index) {
    
    assert(index >= 0);
    assert(size >= index);

    if (index == 0) {
        this->InsertHead(payload);
        return;
    }

    if (index == size) {
        this->InsertTail(payload);
        return;
    }

    Node<T>* iter = this->head;
    for(int i = 0; i < index-1; i++) {
        iter = iter->next;
    }

    Node<T>* node = new Node<T>;
    node->payload = payload;
    node->next = iter->next;

    iter->next = node;
    size++;
}

template <typename T>
T LinkedList<T>::Delete(int index) {
    
    assert(size > index);
    assert(index >= 0);
    assert(size > 0);

    if (index == 0)
        return this->DeleteHead();

    if (index == size-1)
        return this->DeleteTail();

    Node<T>* iter = this->head;
    for(int i = 0; i < index-1; i++) {
        iter = iter->next;
    }

    Node<T>* del = iter->next;
    T ret = del->payload;

    iter->next = del->next;
    
    delete del;
    size--;
    return ret;
}

template <typename T>
T LinkedList<T>::Traverse(int index) {
    
    assert(size != 0);
    assert(size > index);
    assert(index >= 0);

    Node<T>* iter = this->head;

    for(int i = 0; i < index; i++) {
        iter = iter->next;
    }

    return iter->payload;
}

template <typename T>
int LinkedList<T>::LinearSearch(T payload_value) {
    assert(this->size != 0);

    Node<T>* iter = this->head;
    int index = 0;

    while(iter != NULL) {
        if (iter->payload == payload_value) {
            return index;
        }

        iter = iter->next;
        index++;
    }

    return -1;
}

template <typename T>
void LinkedList<T>::PrintList() {
    Node<T>* iter = this->head;

    while(iter != NULL) {
        cout << iter->payload << "-->";
        iter = iter->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
int LinkedList<T>::Swap(LinkedList<T> &L) {
    if (this->length() != L.length())
        return -1;

    LinkedList<T> A;

    while(this->length() != 0) {
        A.InsertHead(this->DeleteTail());
        A.InsertHead(this->DeleteTail());
    }

    while(L.length() != 0) {
        this->InsertHead(L.DeleteTail());
    }

    while(A.length() != 0) {
        L.InsertHead(A.DeleteTail());
    }

    return 0;
}

template <typename T>
void LinkedList<T>::DeleteList() {
    while(this->size != 0) {
        this->DeleteHead();
    }
}

template <typename T>
uint32_t LinkedList<T>::length() {
    return size;
}

template <typename T>
string LinkedList<T>::type() {
    return "LinkedList";
}

#endif