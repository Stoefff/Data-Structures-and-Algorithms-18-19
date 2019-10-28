#include "DanceFloor.h"

DanceFloor::DanceFloor():arr(nullptr), size(0), cap(2){
    Conga first;
    first.pushBack("Integralcho", "fmi");
    arr = new Conga[cap];
    arr[0] = first;
    size++;
}

DanceFloor::DanceFloor(const DanceFloor& rhs):
    arr(nullptr), size(0), cap(0){
    copy(rhs);
}

DanceFloor& DanceFloor::operator=(const DanceFloor& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

DanceFloor::~DanceFloor(){
    free();
}

void DanceFloor::free(){
    delete[] arr;
    arr = nullptr;
    size = 0;
    cap = 0;
}

void DanceFloor::copy(const DanceFloor& rhs){
    arr = new Conga[rhs.cap];
    size = rhs.size;
    cap = rhs.cap;
    for(size_t i = 0; i < size; i++){
        arr[i] = rhs.arr[i];
    }
}

void DanceFloor::resize(const int newSize){
    if (newSize == -1){
        cap *= 2;
    } else {
        cap = newSize;
    }
    Conga* temp = new Conga[cap];
    for(size_t i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    temp = nullptr;
}

const Conga& DanceFloor::operator[](const size_t index) const {
    if (index >= size){
        throw std::logic_error("Out of range");
    }
    return arr[index];
}

Conga& DanceFloor::operator[](const size_t index) {
    return const_cast<Conga& >(
            static_cast<const DanceFloor&>(*this)[index]
    );
}

size_t DanceFloor::getSize() const {
    return size;
}

size_t DanceFloor::getCap() const {
    return cap;
}

bool DanceFloor::empty() const {
    return size == 0;
}

void DanceFloor::print(std::ostream& os) const {
    for(size_t i = 0; i < size; i++){
        os << "Line" << i << ": ";
        arr[i].print(os);
        os <<  " \n";
    }
}

void DanceFloor::pushBack(const Conga& el) {
    if (size >= cap){
        size_t newCap = cap == 0? 2 : cap*2;
        resize(newCap);
    }
    arr[size++] = el;
}

void DanceFloor::popBack() {
    if(size){
        size--;
    } else {
        throw std::logic_error("Popping form empty array");
    }
    if (cap > size*2){
        size_t newCap = (cap == 0? 0 : cap/2);
        resize(newCap);
    }
}

void DanceFloor::removeAt(const size_t index) {
    if (index >= size){
        throw std::logic_error("Out of range!");
    }
    arr[index] = arr[size-1];
    popBack();
}

void DanceFloor::merge(const size_t index1 , const size_t index2){
    if ((index1 >= size)||(index2 >= size)||(index1 == index2)){
        std::cerr << "Ivalid indexes" << "\n";
        return;
    }
    Student oldBackSt = arr[index1].back();
    Student oldFrontSt = arr[index2].front();
    if (!oldFrontSt.isFriend(oldBackSt)){
        std::cerr << "Incompatible people" << "\n";
        return;
    }
    arr[index1].appendWith(arr[index2]);
    removeAt(index2);
}
