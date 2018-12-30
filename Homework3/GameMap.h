#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <fstream>

using std::string;
using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;
using std::queue;
using std::ifstream;

class GameMap{
private:

    // representing egde : neighbor zone and key for passing to it
    using edge = pair<string, string>;
    using adjVerteces = vector<edge>;
    using keyHash = unordered_set<string>;

    struct Zone{
        adjVerteces adjZones;
        keyHash keys;
        bool isAccessible;

        Zone(): isAccessible(false){
        }
    };

private:
    using graph = unordered_map<string, Zone>;
    graph gameMap;

public:
    GameMap() = default;
    GameMap(const GameMap& rhs) = delete;
    GameMap& operator=(GameMap& rhs) = delete;
    ~GameMap() = default;

public:
    void parseGameMap(ifstream& file);
    void exploreGameMap(const string start);
    void generateDOTFile() const;

    void printGameMap() const;

private:
    void parseZones(ifstream& file);
    void parseKeys(ifstream& file);

    void bfs(const string start, keyHash& collectedKeys);

};