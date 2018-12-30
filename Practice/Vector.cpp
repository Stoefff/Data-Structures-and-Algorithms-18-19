#include <iostream>

class Vector{
public:
    Vector();
    Vector(size_t cap);
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);
    ~Vector();

    void pushBack(int el);
    void popBack();

    void insertAt(int el, int index);
    void removeAt(int index);

    const int operator[](const int& index) const;
    int operator[](const int& index);

private:
    void free();
    void copy(const Vector& rhs);
    void resize(size_t newCap);

    int linearSearch(int el);
    int binarySearch(int el, size_t leftIndex, size_t rightIndex);

private:
    int* arr;
    size_t cap;
    size_t size;
};

Vector::Vector()
    :cap(2), size(0){
    arr = new int[cap];
}

Vector::Vector(size_t cap)
    :cap(cap), size(0){
    arr = new int[cap];
}

Vector::Vector(const Vector& rhs){
    copy(rhs);
}

Vector& Vector::operator=(const Vector& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Vector::~Vector(){
    free();
}

void Vector::free(){
    delete[] arr;
    size = 0;
    cap = 0;
}

void Vector::copy(const Vector& rhs){
    this->size = rhs.size;
    this->cap = rhs.cap;
    this->arr = new int[cap];
    for (int i = 0; i < size; i++){
        arr[i] = rhs.arr[i];
    }
}

void Vector::resize(size_t newCap){
    int* temp = new int[newCap];
    for (int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    temp = nullptr;
    cap = newCap;
}

int Vector::linearSearch(int el){
    for (int i = 0; i < size; i++){
        if (arr[i] == el){
            return i;
        }
    }
    return -1;
}

int Vector::binarySearch(int el, size_t leftIndex, size_t rightIndex){
    if (leftIndex > rightIndex)
        return -1;
    int medIndex  = (leftIndex + rightIndex) / 2;
    if (el == arr[medIndex])
        return medIndex;
    if (el > arr[medIndex])
        return binarySearch(el, medIndex + 1, rightIndex);
    if (el < arr[medIndex])
        return binarySearch(el, leftIndex, medIndex + 1);
    return -1;
}

void Vector::pushBack(int el){
    if(size >= cap){
        int newCap = (cap == 0 ? 2 : cap*2);
        resize(newCap);
    }
    arr[size++] = el;
}

void Vector::popBack(){
    size--;
    if (size < cap*2){
        int newCap = (size == 0 ? 2 : cap / 2);
        resize(newCap);
    }
}

void Vector::insertAt(int el, int index){
    if(index >= size){
        return; // error
    }
    pushBack(el);
    for(int i = index; i < size; i++){
        std::swap(arr[i], arr[size-1]);
    }
}

void Vector::removeAt(int index){
    //
}

const int& Vector::operator[](const int& index) const {
    if (index >= size){
        throw std::out_of_range("Out of range");
    }
    return arr[index];
}

int& Vector::operator[](const int& index){
    //return const_cast<int&>(static_cast<const Vector&>(*this)[index]);
}

int main(){

    return 0;
}