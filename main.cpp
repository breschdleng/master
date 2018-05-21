#include <QCoreApplication>
#include <iostream>
#include <linkedlist.h>

using namespace std;

int main()
{

    LinkedList<int> *list = new LinkedList<int>();

    for (int var = 0; var < 5; ++var)
    {
        int init = rand()/10e7;
        std::cout<<"inside main.."<<init<<std::endl;
        list->Add(init);
    }

    list->PrintList();
    list->RemoveAt(3);
    list->PrintList();
    list->Reverse();
    list->PrintList();

    delete list;
    return 0;
}
