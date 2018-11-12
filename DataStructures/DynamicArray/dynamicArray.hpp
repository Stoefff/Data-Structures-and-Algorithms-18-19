#ifndef __DYN__ARR__HEADER__
#define __DYN__ARR__HEADER__

#include <iostream>
using std::cout;
using std::endl;

template <class T>
class DynamicArray {
// Object life cycle
public:
    DynamicArray();
    DynamicArray(size_t cap);
    DynamicArray(const DynamicArray<T>& rhs);
    DynamicArray& operator=(const DynamicArray<T>& rhs);
    ~DynamicArray();

// Interface function
public:
    void pushBack(const T& el);  // Amortized O(1)
    void popBack();              // Amortized O(1)

    void insertAt(const size_t index, const T& el);
    void removeAt(const size_t index, bool keepOrder = true);

    const T& operator[](const size_t index) const;
    T& operator[](const size_t index);

    int find(const T& el) const;
    void insertionSort();

    size_t getSize() const;
    size_t getCapacity() const;
    bool isEmpty() const;

    void printElements(std::ostream& os) const;

private:
    void free();
    void copy(const DynamicArray<T>& rhs);
    void resize(int newSize = -1); // Value: -1 when no new size passed

    int linearSearch(const T& el) const;
    int binarySearch(const T& el) const;

public:
    class iterator{

    };

private:
    T* arr;
    size_t size;
    size_t cap;

    bool isSorted;
};

template <typename T>
DynamicArray<T>::DynamicArray(): arr(nullptr), size(0), cap(0), isSorted(false){
}

template <typename T>
DynamicArray<T>::DynamicArray(size_t cap): arr(nullptr), size(0), cap(cap), isSorted(false){
    arr = new T[cap];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& rhs): arr(nullptr),
    size(0), cap(0), isSorted(false) {
    copy(rhs);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    free();
}

template <typename T>
void DynamicArray<T>::copy(const DynamicArray<T>& rhs){
    cap = rhs.cap;
    size = rhs.size;
    arr = new T[rhs.cap];
    for (int i = 0; i < rhs.size; i++){
        arr[i] = rhs.arr[i];
    }
    isSorted = rhs.isSorted;
}

template <typename T>
void DynamicArray<T>::free(){
    delete[] arr;
    arr = nullptr;
    size = 0;
    cap = 0;
    isSorted = false;
}

template <typename T>
// WARNING: possibly very wrong, beacause of the default parameter
void DynamicArray<T>::resize(int newSize){
    if (newSize == 1){
        this->cap *= 2;
    } else {
        this->cap = newSize;
    }
    T* temp = new T[cap];
    for (int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    temp = nullptr;
}

template <typename T>
int DynamicArray<T>::linearSearch(const T& el) const {
    for (int i = 0; i < size; i++){
        if (arr[i] == el){
            return i;
        }
    }
    cout << "No " << el << " element found." << endl;
    return -1;
}

template <typename T>
int DynamicArray<T>::binarySearch(const T& el) const {
    int start = 0;
    int end = size-1;
    int med = (start + end) / 2;
    while(start <= end) {
        if (arr[med] == el){
            return med;
        }
        if(arr[med] > el){
            end = med;
            med = (start + end) / 2;
        } else {
            start = med;
            med = (start + end) / 2;
        }
    }
    cout << "No " << el << " element found." << endl;
    return -1;
}

template <typename T>
int DynamicArray<T>::find(const T& el) const {
    if (isSorted) {
        return binarySearch(el);
    }
    return linearSearch(el);
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
size_t DynamicArray<T>::getCapacity() const {
    return cap;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void DynamicArray<T>::printElements(std::ostream& os) const {
    os << "Elements: " << '\n';
    if (size == 0){
        os << "{ }" << '\n';
        return ;
    }
    os << "{ ";
    for (int i = 0; i < size - 1; i++) {
        os << arr[i] << ", ";
    }
    os << arr[size -1] << " }\n";
}

template <typename T>
const T& DynamicArray<T>::operator[](const size_t index) const {
    if (index >= size)
        throw std::out_of_range("Out of range");
    return arr[index];
}

template <typename T>
T& DynamicArray<T>::operator[](const size_t index){
    return const_cast<T&>(
        static_cast<const DynamicArray&>(*this)[index]
    );
}

template <typename T>
void DynamicArray<T>::insertionSort() {
    for (int i = 1; i < size; i++){
        for (int j = i; ((j > 0) && (arr[j] < arr[j-1])); j--) {
            T temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

template <typename T>
void DynamicArray<T>::pushBack(const T& el){
    if(size == cap){
        size_t newCap = (cap == 0? 2 : cap * 2);
        resize(newCap);
    }
    arr[size++] = el;
}

template <typename T>
void DynamicArray<T>::popBack() {
    if (size)
        size--;
    else
        throw std::logic_error("Empty dynamic array");
    //Optional downsizing
    if (cap >= size * 2){
        size_t newCap = (cap == 0 ? 0 : cap / 2);
        resize(newCap);
    }
}

template <typename T>
void DynamicArray<T>::insertAt(const size_t index, const T& el){
    pushBack(el);
    for (int i = size -1; i > index; i--)
        std::swap(arr[i], arr[i-1]);
}

template <typename T>
void DynamicArray<T>::removeAt(const size_t index, bool keepOrder){
    if ((index >= size) || (index == 1)){
        popBack();
        return;
    }
    if(keepOrder){
        for(int i = index; i < size - 1; i++)
            std::swap(arr[i], arr[i+1]);
        popBack();
        return;
    }
    std::swap(arr[index], arr[size-1]);
    popBack();
}


#endif
