#include "System.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Compiled on Ubuntu with:
// g++ -std=c++11 -Wall main.cpp Conga.cpp Student.cpp DanceFloor.cpp System.cpp

int main(){

    System sys;
    sys.run();

    return 0;
}

/*
Conga list;
Conga otherList;

list.pushBack("July", "fmi");
list.print(cout);
list.pushBack("Pesho", "unss");
list.print(cout);

list.pushBack("goshe", "tu");
list.pushBack("plamen", "fmi");
list.print(cout);
list.pushBack("ivan", "tu");
list.print(cout);
list.popBack();
list.print(cout);

list.pushFront("toto", "fmi");
list.print(cout);

list.popFront();
list.print(cout);

otherList = list;
otherList.print(cout);

cout << "Here is ok" << "\n";

Conga newConga = list.removeByName("Pesho");
list.print(cout);
newConga.print(cout);

Conga one;
one.pushBack("july", "fmi");
Conga two;
two.pushBack("pesho", "fmi");
one.appendWith(two);
one.print(cout);
two.print(cout)
*/

/*
DanceFloor floor;
floor[0].pushBack("July", "fmi");
floor[0].pushBack("Pesho", "unss");
floor[0].pushBack("goshe", "tu");
floor[0].pushBack("plamen", "tu");
Conga other = floor[0].removeByName("goshe");
floor.pushBack(other);
floor.print(cout);


floor.merge(0,1);
floor.removeAt(1);
floor.print(cout);
*/
