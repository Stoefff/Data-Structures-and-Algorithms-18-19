#include <iostream>
#include "Horo.h"
#include "System.h"

using std::cout;
using std::endl;

// Compile options on Ubuntu 64-bit
// g++ -std=c++11 -Wall main.cpp Horo.cpp System.cpp

int main(int argc, char* argv[]){
    string filename = argv[argc - 1];

    cout << "The program only works with single word labels for now!" << endl;

    System sys(filename);
    sys.run();

    return 0;
}
/*
// All works
    Horo* horo = new Horo();
    horo->insert("July", "", "");
    horo->insert("Bobi", "July", "");
    horo->insert("Alex", "Bobi", "");
    horo->insert("Pesho", "Alex", "");
    horo->insert("Misho", "Pesho", "");
    horo->insert("Mitko", "Misho", "July");

    horo->release("July", "both");
    horo->release("Bobi", "left");
    horo->release("Mitko", "right");

    horo->remove("July");

    horo->release("Pesho", "left");

    horo->print();

    cout << endl;

    horo->add("Kireto", "Mitko", "Bobi");

    horo->print("Kireto");

    cout << endl << horo->getRightName("Kireto") << endl;

    delete horo;
    return 0;
*/

