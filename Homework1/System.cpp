#include "System.h"
#include <cmath>
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

System::System(): floor(DanceFloor()){
    isRunning = true;
}

size_t System::charToInt(const char* str){
    int counter = 0;
    const char* strIt = str;
    while(*strIt != '\0'){
        counter++;
        strIt++;
    }
    size_t num = 0;
    strIt = str;
    while(*strIt != '\0'){
        counter--;
        num += (*strIt - '0') * (int)pow(10, counter);
        strIt++;
    }
    return num;
}

void System::appendF(const char* name, const char* uni, size_t index){
    try{
        floor[index].pushBack(name, uni);
    } catch (std::logic_error& ex) {
        cerr << "No Conga with this index" << endl;
    }
}

// Logic about quitting
void System::removeLastF(size_t index){
    floor[index].popBack();
    if(floor[index].empty()){
        floor.removeAt(index);
    }
}

void System::removeFirstF(size_t index){
    floor[index].popFront();
    if(floor[index].empty()){
        floor.removeAt(index);
    }
}

void System::removeF(const char* name, size_t index){
    try {
        Conga el = floor[index].removeByName(name);
        if (!el.empty())
            floor.pushBack(el);
        if (floor[index].empty())
            floor.removeAt(index);
    } catch (std::invalid_argument& ex) {
        cerr << ex.what() << endl;
    }
}

void System::mergeF(size_t index1, size_t index2){
    floor.merge(index1, index2);
}

void System::run() {
    const char* quit = "quit";
    const char* append = "append";
    const char* remove = "remove";
    const char* merge = "merge";
    const char* print = "print";
    const char* removeLast = "removeLast";
    const char* removeFirst = "removeFirst";
    // Re-write them to be dynamic later
    char argument[64], argument1[64], argument2[64], argument3[64];
    while (isRunning){
        cout << "Enter command:" << endl;
        cin >> argument;
        if ((strcmp(argument, quit) == 0) || (floor.empty())){
            isRunning = false;
        } else if(strcmp(argument, append) == 0){
            cin >> argument1 >> argument2 >> argument3;
            appendF(argument1, argument2, charToInt(argument3));
        } else if(strcmp(argument, removeLast) == 0){
            cin >> argument1;
            removeLastF(charToInt(argument1));
        } else if(strcmp(argument, removeFirst) == 0){
            cin >> argument1;
            removeFirstF(charToInt(argument1));
        } else if(strcmp(argument, remove) == 0){
            cin >> argument1 >> argument2;
            removeF(argument1, charToInt(argument2));
        } else if(strcmp(argument, merge) == 0){
            cin >> argument1 >> argument2;
            mergeF(charToInt(argument1), charToInt(argument2));
        } else if(strcmp(argument, print) == 0){
            floor.print(cout);
        } else {
            cout << "Invalid command, enter a new one." << endl;
            cout.clear();
        }
        if (floor.empty()){
            isRunning = false;
            cout << "Dance club closing" << endl;
        }
    }
}
