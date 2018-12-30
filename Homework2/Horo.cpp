#include "Horo.h"
#include <stdexcept>
#include <iostream>

using std::logic_error;
using std::cerr;
using std::cout;
using std::endl;

Horo::Horo(size_t size): horo(size){
}

Horo::~Horo(){
    for(hashChain& chain: horo)
        if(!chain.empty())
            for(dancer& current: chain){
                delete current;
                current = nullptr;
            }
}

void Horo::clearPointers(){
    for(hashChain& chain: horo)
        if(!chain.empty())
            for(dancer& current: chain){
                current = nullptr;
            }
}

// Testing Vanaka's hash fucntion
size_t Horo::hashFunc(const string& key, size_t size){
    size_t result = key.size();
    for(unsigned char c: key){
        result += c;
    }
    return result & (size -1);
}

// Shared | Weak pointer semantics
void Horo::rehash(){
    Horo newHoro (horo.size()*2);
    for (hashChain& chain: horo){
        if (!chain.empty()){
            for(dancer& current: chain){
                newHoro.horo[newHoro
                    .hashFunc(current->name, newHoro.horo.size())]
                    .push_front(current);
            }
        }
    }
    newHoro.horo.swap(horo);
    newHoro.clearPointers();
}

bool Horo::empty(const string& firstDancerName) {
    try {
        dancer first = get(firstDancerName);
        if(first->leftDancer == first->rightDancer &&
            first->leftDancer->leftDancer == first &&
            first->leftDancer->rightDancer == first)
            return true;
        else
            return false;
    } catch (logic_error& ex) {
        cerr << "The first dancer not present!" << endl;
        return true;
    }
}

// Still O(1) cause the chain is limited to 5 elements
Horo::chainIter Horo::find(size_t index, const string& key) {
    chainIter it = horo[index].begin();
    while (it != horo[index].end() && (*it)->name != key){
        it++;
    }
    return it;
}

Horo::dancer Horo::get(const string& name) {
    size_t index = hashFunc(name, horo.size());
    chainIter it = find(index, name);
    if (it == horo[index].end()){
        // Magic implicit casts to string ???????
        throw logic_error("No dancer " + name + "\n");
    }
    return *it;
}

bool Horo::areNeighbors(const dancer left, const dancer right) const{
    return ((left->rightDancer == right) && (right->leftDancer == left));
}

void Horo::insert(const string& name, const string& leftDancerName,
    const string& rightDancerName){
    try{
        size_t index = hashFunc(name, horo.size());

        chainIter it = find(index, name);
        if (it != horo[index].end()){
            throw logic_error(name + " is already dancing\n");
        }
        if (horo[index].size() >= maxChainSize){
            rehash();
            index = hashFunc(name, horo.size());
        }
        if ((leftDancerName.empty())&&(rightDancerName.empty())){
            dancer newDancer = new DancerInfo(name);
            horo[index].push_front(newDancer);
            return;
        }
        if(!(leftDancerName.empty())&&(rightDancerName.empty())){
            dancer leftDancer = get(leftDancerName);
            dancer newDancer = new DancerInfo(name, leftDancer, true);
            horo[index].push_front(newDancer);
            leftDancer->rightDancer = newDancer;
            leftDancer->isRightConn = true;
            return;
        }
        if(!(leftDancerName.empty())&&!(rightDancerName.empty())){
            dancer leftDancer = get(leftDancerName);
            dancer rightDancer = get(rightDancerName);
            dancer newDancer = new DancerInfo(name, leftDancer, true,
                rightDancer, true);
            horo[index].push_front(newDancer);
            leftDancer->rightDancer = newDancer;
            leftDancer->isRightConn = true;
            rightDancer->leftDancer = newDancer;
            rightDancer->isLeftConn = true;
            return;
        }
        throw logic_error("Something is wrong, inserting abourting!\n");
    } catch (logic_error& ex){
        cerr << ex.what();
    }
}

void Horo::add(const string& name, const string& leftDancerName,
    const string& rightDancerName){
    try{
        size_t index = hashFunc(name, horo.size());

        chainIter it = find(index, name);
        if (it != horo[index].end()){
            throw logic_error(name + " is already dancing\n");
        }
        dancer leftDancer = get(leftDancerName);
        dancer rightDancer = get(rightDancerName);
        if (!areNeighbors(leftDancer, rightDancer)){
            throw logic_error(leftDancer->name + " and " + rightDancer->name +
            " are not neighbors \n");
        }
        insert(name, leftDancer->name, rightDancer->name);
    } catch (logic_error& ex){
        cerr << ex.what();
    }
}

void Horo::remove(const string& name){
    try{
        dancer current = get(name);
        if (
            !current->isLeftConn &&
            !current->isRightConn &&
            !current->leftDancer->isRightConn &&
            !current->rightDancer->isLeftConn
        ){
            current->leftDancer->rightDancer = current->rightDancer;
            current->rightDancer->leftDancer = current->leftDancer;
            size_t index = hashFunc(name, horo.size());
            horo[index].erase(find(index, name));
            delete current;
            cout << "Free at last" << endl;
        } else {
            cout << "This wont't be so easy" << endl;
        }
    } catch (logic_error& ex){
        cerr << ex.what();
    }
}

void Horo::swap(const string& dancer1, const string& dancer2){
    try{
        dancer leftDancer = get(dancer1);
        dancer rightDancer = get(dancer2);
        if (!areNeighbors(leftDancer, rightDancer)){
            throw logic_error(leftDancer->name + " and " + rightDancer->name +
            " are not neighbors \n");
        }
        if (leftDancer->rightDancer != rightDancer){
            dancer temp = rightDancer;
            rightDancer = leftDancer;
            leftDancer = temp;
        }
        if (
            !leftDancer->isLeftConn &&
            !rightDancer->isRightConn &&
            !leftDancer->leftDancer->isRightConn &&
            !rightDancer->rightDancer->isLeftConn
        )
            leftDancer->leftDancer->rightDancer = rightDancer;
            rightDancer->rightDancer->leftDancer = leftDancer;
            leftDancer->isLeftConn = true;
            leftDancer->isRightConn = false;
            rightDancer->isRightConn = true;
            rightDancer->isLeftConn = false;
            leftDancer->rightDancer = rightDancer->rightDancer;
            dancer temp = leftDancer->leftDancer;
            leftDancer->leftDancer= rightDancer;
            rightDancer->leftDancer= temp;
            rightDancer->rightDancer = leftDancer;
            temp = leftDancer;
            leftDancer = rightDancer;
            rightDancer = leftDancer;
    } catch (logic_error& ex){
        cerr << ex.what() << endl;
    }
}

void Horo::release(const string& name, const string& who){
    try{
        dancer current = get(name);
        if (who == "left")
            current->isLeftConn = false;
        if (who == "right")
            current->isRightConn = false;
        if (who == "both"){
            current->isLeftConn = false;
            current->isRightConn = false;
        }
    } catch (logic_error& ex){
        cerr << ex.what() << endl;
    }
}

void Horo::grab(const string& name, const string& who){
    try{
        dancer current = get(name);
        if (who == "left")
            current->isLeftConn = true;
        if (who == "right")
            current->isRightConn = true;
        if (who == "both"){
            current->isLeftConn = true;
            current->isRightConn = true;
        }
    } catch (logic_error& ex){
        cerr << ex.what() << endl;
    }
}

void Horo::printInfo(const string& name) {
    try{
        dancer current = get(name);
        cout << current->leftDancer->name << " ";
        printRelation(current->leftDancer, current);
        cout << current->name << " ";
        printRelation(current, current->rightDancer);
        cout << current->rightDancer->name << " " << endl;
    } catch (logic_error& ex){
        cerr << ex.what();
    }
}

void Horo::print() {
    for(hashChain& chain: horo)
        if(!chain.empty())
        for(dancer& current: chain)
            printInfo(current->name);
}

void Horo::print(const string& firstDancerName){
    try{
        dancer first = get(firstDancerName);
        cout << first->name << endl;
        dancer current = first->rightDancer;
        while (current != first){
            cout << current->name << endl;
            current = current->rightDancer;
        }
    } catch (logic_error& ex){
        cerr << ex.what() << endl;
    }
}

void Horo::printRelation(const dancer leftDancer, const dancer rightDancer) {
    if((leftDancer->isRightConn)&&(rightDancer->isLeftConn)){
        cout << "<--> ";
        return;
    }
    if(!(leftDancer->isRightConn)&&(rightDancer->isLeftConn)){
        cout << "<--- ";
        return;
    }
    if((leftDancer->isRightConn)&&!(rightDancer->isLeftConn)){
        cout << "---> ";
        return;
    }
    if(!(leftDancer->isRightConn)&&!(rightDancer->isLeftConn)){
        cout << "---- ";
        return;
    }
}

string Horo::getRightName(const string& name){
    dancer current = get(name);
    return current->rightDancer->name;
}
