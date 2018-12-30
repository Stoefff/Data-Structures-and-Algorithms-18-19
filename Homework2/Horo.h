#pragma once

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::pair;
using std::istream;

class Horo{
private:
    struct DancerInfo {
        string name;
        DancerInfo* leftDancer;
        bool isLeftConn;
        DancerInfo* rightDancer;
        bool isRightConn;

        DancerInfo(const string& name,
            DancerInfo* leftDancer = nullptr, bool isLeftConn = false,
            DancerInfo* rightDancer = nullptr, bool isRightConn = false):
            name(name), leftDancer(leftDancer), isLeftConn(isLeftConn),
            rightDancer(rightDancer), isRightConn(isRightConn){
        }
    };

    using dancer = DancerInfo*;
    using hashChain = list <dancer>;
    using hashTable = vector <hashChain>;
    using chainIter = hashChain::iterator;

private:
    hashTable horo;
    static const size_t baseHashSize = 2;
    static const size_t maxChainSize = 2; // Change this to 4 later

public:
    Horo(size_t size = baseHashSize);
    Horo(const Horo& rhs) = delete;
    Horo& operator=(const Horo& rhs) = delete;
    ~Horo();

public:
    //Initializing the elements
    void insert(const string& newDancer, const string& leftDancer,
        const string& rightDancer);
    // Add command
    void add(const string& newDancer, const string& leftDancer,
        const string& rightDancer);

    void remove(const string& name);

    void release(const string& name, const string& who);
    void grab(const string& name, const string& who);

    void swap(const string& dancer1, const string& dancer2);

    void print(const string& firstDancerName);
    void printInfo(const string& name);

    // Helpers
    void print();
    bool empty(const string& firstDancerName);
    string getRightName(const string& name);

private:
    static size_t hashFunc(const string& name, size_t size);
    void rehash();

    dancer get(const string& name) ;
    chainIter find(size_t index, const string& key);

    bool areNeighbors(const dancer leftDancer, const dancer rightDancer) const;
    void printRelation(const dancer leftDancer, const dancer rightDancer);

    void clearPointers();
};
