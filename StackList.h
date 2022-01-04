#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

template <typename T>
class StackList : public ADT {
private:
    LinkedList<T> L;

public:
    void Push(T payload);
    T Pop();
    T Top();
    uint32_t length();
    bool isEmpty();
    void PrintStack();
    int Swap(StackList &S);
    string type();
};

template <typename T>
void StackList<T>::Push(T payload) {
    L.InsertHead(payload);
}

template <typename T>
T StackList<T>::Pop() {
    return L.DeleteHead();
}

template <typename T>
T StackList<T>::Top() {
    return L.Traverse(0);
}

template <typename T>
uint32_t StackList<T>::length() {
    return L.length();
}

template <typename T>
bool StackList<T>::isEmpty() {
    return (L.length() == 0);
}

template <typename T>
void StackList<T>::PrintStack() {
    for(int i = 0; i < L.length(); i++) {
        cout << L.Traverse(i) << "<--";
    }
    cout << "BOTTOM" << endl;
}

template <typename T>
int StackList<T>::Swap(StackList<T> &S) {
    if (this->length() != S.length())
        return -1;

    this->L.Swap(S.L);

    return 0;
}

template <typename T>
string StackList<T>::type() {
    return "StackList";
}

#endif