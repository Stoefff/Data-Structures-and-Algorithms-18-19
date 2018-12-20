#include "System.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ios;
using std::ifstream;
using std::runtime_error;
using std::logic_error;
using std::getline;

System::System(const string& filename):
    horo(){
    try {
        parseFile(filename);
        isRunning = true;
    } catch (runtime_error& ex) {
        cerr << ex.what() << endl
            << "Try running the program again"
            << endl;
        isRunning = false;
    }
}

System::~System() {
}

void System::parseFile(const string& filename){
    ifstream file (filename, ios::in);
    if(!file.good()){
        throw runtime_error("Failed to load this file");
    }
    string previous;
    string current;
    getline(file, current);
    firstDancer = current;
    horo.insert(current, "", "");
    while(!file.eof()){
        previous = current;
        getline(file, current);
        if (file.eof())
            horo.insert(current, previous, firstDancer);
        else
            horo.insert(current, previous, "");
    }
    file.close();
}

void System::updateFirst(const string& name){
    try {
        if (name == firstDancer){
            firstDancer = horo.getRightName(name);
        }
    } catch (logic_error& ex){
        cerr << ex.what() << endl;
    }
}


void System::run() {
    string argument, argument1, argument2, argument3;
    while (isRunning){
        cout << "Enter command:" << endl;
        cin >> argument;
        if (argument == "RELEASE"){
            cin >> argument1 >> argument2;
            horo.release(argument1, argument2);
        } else if (argument == "GRAB") {
            cin >> argument1 >> argument2;
            horo.grab(argument1, argument2);
        } else if (argument == "INFO") {
            cin >> argument1;
            horo.printInfo(argument1);
        } else if (argument == "ADD") {
            cin >> argument1 >> argument2 >> argument3;
            horo.add(argument1, argument2, argument3);
        } else if (argument == "REMOVE") {
            cin >> argument1;
            updateFirst(argument1);
            horo.remove(argument1);
        } else if (argument == "SWAP") {
            cin >> argument1 >> argument2;
            horo.swap(argument1, argument2);
        } else if (argument == "PRINT") {
            horo.print(firstDancer);
        } else if (argument == "EXIT") {
            isRunning = false;
        } else
            cout << "Invalid command, enter a new one" << endl;
        if (horo.empty(firstDancer)){
            isRunning = false;
            cout << "... and the music stops" << endl;
        }
    }
}
