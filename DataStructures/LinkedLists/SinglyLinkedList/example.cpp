#include "LinkedList.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    LinkedList<int> list;
    LinkedList<int> otherList;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.popBack();
    list.printElements(cout);

    list.insertAfter(2, 41);
    list.printElements(cout);

    list.removeAfter(2);
    list.printElements(cout);

    list.popFront();
    list.printElements(cout);

    list.pushFront(69);
    list.printElements(cout);

    otherList = list;
    otherList.printElements(cout);

    LinkedList<int> list2 = list;
    list2.printElements(cout);


    cout << "Hello World!" << endl;
    return 0;
}
