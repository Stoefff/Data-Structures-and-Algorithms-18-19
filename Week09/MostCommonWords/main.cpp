#include "../../../FMI-DSA/data_structures/hash_table/template_hash_map/hash_map.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ios;
using std::ifstream;
using std::cerr;
using std::endl;

/*
Structure:

hashMap <key, data>
    key is the word
    data is :
        set<string> left;
        set<string> right;
        size_t counter = 0;

teble[current].counter++; // add word in all cases
*/

void getWordsArray(char* fileName){
    ifstream file (fileName, ios::in);
    if(!file.good()){
        cerr << "File stream failed!" << endl;
        return;
    }
}

int main(int argc, char* argv[]){
    getWordsArray(argv[1]);
    return 0;
}
