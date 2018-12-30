#include <iostream>
#include "GameMap.h"
#include <fstream>

/*
Compile options on Ubuntu 16.04 64-bit:
g++ -std=c++11 -Wall main.cpp GameMap.cpp

Tested with the example graph from the doc
and two other complex graphs
*/

int main(int argc, char* argv[]) {

    string fileName = argv[1];
    string startZone = argv[2];

    ifstream file (fileName, std::ios::in);
    if (!file.good()){
        std::cerr<< "Error opening the file" << std::endl;
        return -1;
    }

    GameMap map;
    map.parseGameMap(file);
    file.close();

    map.exploreGameMap(startZone);
    //map.printGameMap();
    map.generateDOTFile();


    return 0;
}