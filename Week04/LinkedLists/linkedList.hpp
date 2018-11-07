#ifndef __LINKED__LIST__HEADER__
#define __LINKED__LIST__HEADER__

#include <iostream>
#include <stdexcept>
#include <iosfwd>

template <class T>
class LinkedList {
private:
    struct node {
        T data;
        node* nextNode;

        node(const T& pData, node* pNextNode = nullptr):
            data(pData),
            nextNode(pNextNode){}
    };

private:
    node* frontPtr;
    node* backPtr;
    size_t listSize;

public:
    LinkedList();
    LinkedList(const LinkedList& rhs);
    LinkedList& operator=(const LinkedList& rhs);
    ~LinkedList();

private:
    void copy(const LinkedList& rhs);
    void free();

public:
    void pushBack(const T& data); // O(1)
    void pushFront(const T& data); // O(1)
    void popBack(); // For some reason 0(n)
    void popFront(); // 0(1)

    //lookup for the last element O(1)
	const T& back() const;
	T& back();
	//lookup for the first element O(1)
	const T& front() const;
	T& front();

    bool isEmpty() const;
    size_t getSize() const;
    void printData(std::ostream& os) const;
};

template <typename T>
LinkedList<T>::LinkedList():
    frontPtr(nullptr),
    backPtr(nullptr),
    listSize(0){
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs):
    frontPtr(nullptr),
    backPtr(nullptr),
    listSize(0){
    copy(rhs);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    free();
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& rhs){

}



#endif
