#ifndef __VECTOR__HEADER__
#define __VECTOR__HEADER__

#include <iostream>

template <class T>
class Vector {
public:
    Vector();
    Vector(const Vector<T>& rhs);
    Vector<T>& operator=(const Vector<T>& rhs);
    ~Vector();

    void pushBack(const T& value);
    void insertAt(const T& value, const size_t pos);

    void popBack();
    void RemoveAt(const size_t pos);

    int getSize() const;

    int search(const T& val);

    T& operator[](const int i);
    const T& operator[](const int i) const;

private:
    //Maybe add a smart resize like Semerdzhiev explained ???
    //void reserve();
    void resize();
    void copy(const Vector<T>& rhs);
    void free();
    void sort();
    int linearSearch(const T& val);
    int binarySearch(const T& val);

private:
    T* arr;
    size_t size;
    size_t cap;

    bool isSorted;
};

template <class T>
Vector<T>::Vector()
    :size(0)
    ,cap(2)
    ,arr(nullptr)
    ,isSorted(false){
    this->arr = new T[cap];
}

template <class T>
Vector<T>::Vector(const Vector<T>& rhs){
    copy(rhs);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

template <class T>
Vector<T>::~Vector(){
    free();
}

template <class T>
void Vector<T>::free(){
    delete[] arr;
    arr = nullptr;
    size = 0;
    cap = 0;
    isSorted = false;
}

template <class T>
void Vector<T>::copy(const Vector<T>& rhs){
    this->cap = rhs.cap;
    this->size = rhs.size;
    isSorted = false;
    this->arr = new T[this->cap];
    for(size_t i = 0; i < size; i++){
        this->arr[i] = rhs.arr[i];
    }
}

template <class T>
void Vector<T>::resize(){
    T* temp = new T[cap*2];
    for(size_t i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    delete[] arr;
    arr = temp;
    temp = nullptr;
    cap *= 2;
}

template <class T>
void Vector<T>::pushBack(const T& value){
    if (size >= cap){
        resize();
    }
    arr[size] = value;
    size++;
    isSorted = false;
}

template <class T>
void Vector<T>::popBack(){
    if (size) {
        size--;
    } else {
        //throw an appropriate error
    }
    //Maybe do a cheeky resize here
}

template <class T>
void Vector<T>::sort(){
    T temp;
    for(size_t i=1; i < size; i++){
        for(size_t j = i - 1; j > 0 && arr[j-1] > arr[j]; j--){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    isSorted = true;
}

template <class T>
int Vector<T>::linearSearch(const T& val){
    for(int i = 0; i < size; i++){
        if (arr[i] == val){
            return i;
        }
    }
    return -1;
}

template <class T>
int Vector<T>::binarySearch(const T& val){
    int beg = 0;
	int end = size;
	int middle = (beg + end) / 2 ;

	while (beg <= end){
		if (arr[middle] > val) //the element is on the left side of the middle
		{
			end = middle - 1;
			middle = (beg + end) / 2;
		}
		else if (arr[middle] < val) //the element is on the right side of the middle
		{
			beg = middle + 1;
			middle = (beg + end) / 2;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

template <class T>
int Vector<T>::getSize() const{}

template <class T>
T& Vector<T>::operator[](const int i){
    if ((i < size)&&(i > 0)){
        return arr[i];
    }
}

template <class T>
const T& Vector<T>::operator[](const int i) const {
    if ((i < size)&&(i > 0)){
        return arr[i];
    }
}

template <class T>
Vector<T> reverse(const Vector<T>& other){
    Vector<T> reversed;
    for()
}
#endif
