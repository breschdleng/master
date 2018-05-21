#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<algorithm>

template<typename T>
class LinkedList
{
public:
    struct Node
    {
        Node *pNext;
        T value;
    };
    LinkedList();
    ~LinkedList();

    void Add(T value);
    void RemoveAt(int idx);
    void Reverse();    
    void PrintList();
    size_t& GetSize();

private:
    size_t m_size;
    Node *m_pHead;
    Node *m_pTail;    
    void Deallocate();

};
#include <linkedlist.hpp>

#endif // LINKEDLIST_H
