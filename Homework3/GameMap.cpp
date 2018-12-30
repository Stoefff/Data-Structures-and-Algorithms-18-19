#include "GameMap.h"
#include <iostream>

using std::getline;
using std::cout;
using std::endl;
using std::pair;
using std::ofstream;

const string dotFileName = "map.gv";

void GameMap::parseGameMap(ifstream& file){
    string buffer;
    while (!file.eof()){
        getline(file, buffer);
        if (buffer == "[zones]"){
            parseZones(file);
        } else if (buffer == "[keys]"){
            parseKeys(file);
        }
    }
}

// Could be rewritten with string splitting funtion
// which accepts as a param a delimeter
// and returns a vector of the splitted words
// But Bojilov changed the grading scale yet again :))))))
void GameMap::parseZones(ifstream& file){
    string line = "sample";
    while(!file.eof()){
        getline(file, line);
        if (line.empty()){
            break;
        }
        string firstZone;
        string secondZone;
        string key;
        string::iterator it = line.begin();
        while (*it != ' '){
            firstZone += *it;
            it++;
        }
        it++; // Skip the space before ->
        // Skip the ->
        while (*it != ' '){
            it++;
        }
        it++; // Skip the space after
        while ((*it != ' ')&&(*it != ';')){
            secondZone += *it;
            it++;
        }
        // IF there is a key
        if(*it == ' '){
            it++; // Skipping the space before the key;
            it++; // Skipping the [
            while ((*it != ']')){
                key += *it;
                it++;
            }
        }
        edge neightbor = std::make_pair(secondZone, key);
        gameMap[firstZone].adjZones.push_back(neightbor);
        gameMap[secondZone];
    }
}

void GameMap::parseKeys(ifstream& file){
    string line = "sample";
    while(!file.eof()){
        getline(file, line);
        if (line.empty()){
            break;
        }
        string key;
        string zone;
        string::iterator it = line.begin();
        while(*it != '-'){
            key += *it;
            it++;
        }
        key.pop_back(); // Delete the unnessesary space
        it++; // skip the -
        it++; // skip the >
        it++; // skip the space afther the key;
        while(*it != ';'){
            zone += *it;
            it++;
        }
        gameMap[zone].keys.insert(key);
    }
}

void GameMap::exploreGameMap(const string start) {
    keyHash collectedKeys;
    bfs(start, collectedKeys);

}

// Idea: when we collect a key we start a bfs from there
// to open prevously closed door(find a path to them) in the upper bfs
void GameMap::bfs(const string start, keyHash& collectedKeys){
    unordered_set<string> visited;
    queue<string> wave;
    wave.push(start);

    while(!wave.empty()){
        string currentZoneName = wave.front();
        Zone& currentZone = gameMap[currentZoneName];
        visited.insert(currentZoneName);
        currentZone.isAccessible = true;

        // Collecting keys
        for (string key: currentZone.keys){
            if(collectedKeys.find(key) == collectedKeys.end()){
                collectedKeys.insert(key);
                bfs(currentZoneName, collectedKeys);
            }
        }

        //Normal bfs with collected keys
        for (edge adj: currentZone.adjZones){
            if(visited.find(adj.first) == visited.end() &&
                (adj.second == "" ||
                (adj.second != "" &&
                collectedKeys.find(adj.second) != collectedKeys.end()))){
                wave.push(adj.first);
            }
        }
        wave.pop();
    }
}

void GameMap::printGameMap() const{
    for(pair<string, Zone> it: gameMap){
        cout << it.first << " - "
            << (it.second.isAccessible? "Ye": "No") << " - ";
        for (edge edge: it.second.adjZones){
            cout << edge.first << " opened with key: " << edge.second << ", ";
        }
        cout << "[ ";
        for (string key: it.second.keys){
            cout << key << ", ";
        }
        cout << "]" << endl;
    }
}

void GameMap::generateDOTFile() const {
    ofstream file (dotFileName, std::ios::out | std::ios::trunc);
    if (!file.good()){
        std::cerr << "Output file stream failed!" << endl;
        return;
    }
    string tab = "\t";
    string notAccessible = ", color=red, style=filled, fillcolor=\"#ffefef\"";

    file << "digraph { " << endl;
    for (pair<string, Zone> node: gameMap){
        file << tab << node.first << " [label=\"" << node.first;
        if (!node.second.keys.empty()){
            for(string key: node.second.keys){
                file << "\\l" << key;
            }
        }
        file << "\"";
        if (!node.second.isAccessible){
            file << notAccessible;
        }
        file << "];" << endl;
        for (edge adj: node.second.adjZones){
            file << tab << node.first << " -> " << adj.first;
            if (adj.second != ""){
                file << " [label=\"" << adj.second << "\"]";
            }
            file << ";" << endl;
        }
        file << endl;
    }
    file << "}" << endl;
    cout << "DOT file generated" << endl;
    file.close();
}