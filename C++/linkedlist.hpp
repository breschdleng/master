#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

//-----------------------------------------------------------------------//
/*Constructor*/
//-----------------------------------------------------------------------//
template<typename T>
LinkedList<T>::LinkedList():m_size(0),
                            m_pHead(nullptr),
                            m_pTail(nullptr)

{

}
//-----------------------------------------------------------------------//
/*Destructor*/
//-----------------------------------------------------------------------//

template<typename T>
LinkedList<T>::~LinkedList()
{
    Deallocate();
}
//-----------------------------------------------------------------------//
template<typename T>
void LinkedList<T>::Deallocate()
{
    while(m_pHead)
    {
        Node* delNode = m_pHead;
        m_pHead = m_pHead->pNext;
        delete delNode;
    }
}
//-----------------------------------------------------------------------//
template<typename T>
void LinkedList<T>::Add(T value)
{    
    // if first element is added
    if(m_pHead==nullptr)
    {
        Node *m_pNode = new Node();
        m_pNode->value = value;
        m_pHead = m_pNode;
        m_pTail = m_pHead;
        m_pTail->pNext = nullptr;
        m_pHead->pNext = nullptr;

    }    
    // if second element is added
    else if(m_pHead == m_pTail)
    {        
        Node *m_pNode = new Node();
        m_pNode->value = value;

        m_pTail = m_pNode;
        m_pHead->pNext = m_pTail;
    }
    // if third element is added
    else
    {
        Node *m_pNode = new Node();
        m_pNode->value = value;

        m_pTail->pNext = m_pNode;
        m_pTail = m_pTail->pNext;
    }
    m_size++;
}
//-----------------------------------------------------------------------//
template<typename T>
void LinkedList<T>::RemoveAt(int idx)
{
    Node *pTemp = m_pHead;
    Node *delNode = nullptr;

    int listIdx = 0;
    while(pTemp)
    {
        if(idx-1 == listIdx)
        {
            delNode = pTemp->pNext;
            pTemp->pNext = pTemp->pNext->pNext;
        }
        pTemp = pTemp->pNext;
        listIdx++;
    }
delete delNode;
m_size--;
delNode = nullptr;
}
//-----------------------------------------------------------------------//
template<typename T>
void LinkedList<T>::Reverse()
{   
    Node *pPrev = nullptr;
    Node *pTemp = m_pHead;
    Node *pCurr = m_pHead;

    //toDO: check this implementation
    while(pTemp)
    {

        pPrev = pTemp->pNext;
        pPrev->pNext = pCurr;
        pCurr = pPrev;
        pTemp = pTemp->pNext;
// solution:
//        pTemp = pCurr->pNext;
//        pCurr->pNext = pPrev;
//        pPrev = pCurr;
//        pCurr = pCurr->pNext;

    }
    m_pTail = m_pHead;
    m_pHead = pPrev;

}
//-----------------------------------------------------------------------//
template<typename T>
void LinkedList<T>::PrintList()
{
    Node *node = m_pHead;
    std::cout<<"printing elements.."<<std::endl;

    std::cout<<"pHead.."<<m_pHead->value<<std::endl;

    while(node)
    {
        std::cout<<node->value<<std::endl;
        node = node->pNext;
    }
    std::cout<<"pTail.."<<m_pTail->value<<std::endl;
    std::cout<<"m_size.."<<m_size<<std::endl;

}

//-----------------------------------------------------------------------//
template<typename T>
size_t& LinkedList<T>::GetSize()
{
    return m_size;
}


#endif // LINKEDLIST_HPP
