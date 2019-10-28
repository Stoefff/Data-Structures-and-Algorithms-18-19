#include "Conga.h"

Conga::Conga(): frontNode(nullptr), backNode(nullptr), size(0){
}

Conga::Conga(const Conga& rhs):
    frontNode(nullptr), backNode(nullptr), size(0){
    copy(rhs);
}

Conga& Conga::operator=(const Conga& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Conga::~Conga(){
    free();
}

void Conga::free(){
    node* it;
    while (frontNode != nullptr){
        it = frontNode;
        frontNode = frontNode->nextNode;
        delete it;
    }
    size = 0;
    frontNode = nullptr;
    backNode = nullptr;
}

void Conga::copy(const Conga& rhs){
    if(rhs.empty()){
        return;
    }
    try{
        frontNode = new node(rhs.frontNode->student);
        node* thisIt = frontNode;
        node* otherIt = rhs.frontNode;
        while(otherIt->nextNode != nullptr){
            otherIt = otherIt->nextNode;
            thisIt->nextNode = new node(otherIt->student, thisIt);
            thisIt = thisIt->nextNode;
        }
        backNode = thisIt;
    } catch (std::bad_alloc&){
        free();
        throw;
    }
    size = rhs.size;
}

bool Conga::empty() const {
    return size == 0;
}

size_t Conga::getSize() const {
    return size;
}

void Conga::print(std::ostream& os) const {
    node* it = frontNode;
    while(it->nextNode != nullptr){
        it->student.print(os);
        os << " - ";
        it = it->nextNode;
    }
    it->student.print(os);
    //os <<  " \n";
}

void Conga::pushFront(const char* name, const char* uni){
    try {
        Student st (name, uni);
        if(empty()){
            frontNode = new node(st);
            backNode = frontNode;
            size++;
            return;
        }
        if (!frontNode->student.isFriend(st)){
            std::cerr << "Incompatible people" << "\n";
            return;
        }
        frontNode->prevNode = new node(st, nullptr, frontNode);
        frontNode = frontNode->prevNode;
        size++;
    } catch (std::invalid_argument& ex) {
        std::cerr << ex.what() << "\n"
            << "Push terminated!" << "\n";
        return;
    }
}

void Conga::pushBack(const char* name, const char* uni){
    try{
        if(empty()){
            pushFront(name, uni);
            return;
        }
        Student st (name, uni);
        if (!st.isFriend(backNode->student)){
            std::cerr << "Incompatible people" << "\n";
            return;
        }
        backNode->nextNode = new node(st, backNode, nullptr);
        backNode = backNode->nextNode;
        size++;
    } catch (std::invalid_argument& ex) {
        std::cerr << ex.what() << "\n"
            << "Push terminated!" << "\n";
        return;
    }
}

void Conga::popFront(){
    if(empty()){
        std::cerr << "No elements to pop!" << "\n";
        return;
    }
    if (size == 1){
        free();
        return;
    }
    node* temp = frontNode;
    frontNode = frontNode->nextNode;
    delete temp;
    frontNode->prevNode = nullptr;
    size--;
}

void Conga::popBack(){
    if(empty()){
        std::cerr << "No student in this Conga!" << "\n";
        return;
    }
    if (size == 1){
        free();
        return;
    }
    node* temp = backNode;
    backNode = backNode->prevNode;
    backNode->nextNode = nullptr;
    delete temp;
    size--;
}

Conga Conga::removeByName(const char* name){
    if(empty()){
        throw std::invalid_argument("No students in this Conga!");
    }
    node* it = frontNode;
    size_t counter = 1;
    while (!(it->student.sameNames(name)) && it != nullptr){
        it = it->nextNode;
        counter++;
    }
    if (it == nullptr){
        throw std::invalid_argument("No such student found in this Conga!");
    }
    Conga newConga;
    if (it == frontNode){
        popFront();
        return newConga;
    }
    if (it == backNode){
        popBack();
        return newConga;
    }
    newConga.frontNode = it->nextNode;
    newConga.backNode = backNode;
    newConga.size = size - counter;
    backNode = it->prevNode;
    backNode->nextNode = nullptr;
    delete it;
    return newConga;
}

const Student& Conga::front() const{
    return frontNode->student;
}

Student& Conga::front(){
    return const_cast<Student& >(
        static_cast<const Conga&>(*this).front()
    );
}

const Student& Conga::back() const {
    return backNode->student;
}

Student& Conga::back() {
    return const_cast<Student&>(
        static_cast<const Conga&>(*this).back()
    );
}

void Conga::appendWith(Conga& other){
    backNode->nextNode = other.frontNode;
    other.frontNode->prevNode = backNode;
    backNode = other.backNode;
    size += other.size;
    other.frontNode = nullptr;
    other.backNode = nullptr;
    other.size = 0;
}
