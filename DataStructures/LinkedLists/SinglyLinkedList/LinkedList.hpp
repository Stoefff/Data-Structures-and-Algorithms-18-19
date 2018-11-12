#ifndef __LINKED__LIST__HEADER
#define __LINKED__LIST__HEADER

#include <iostream>

template <typename T>
class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList& rhs);
    LinkedList& operator=(const LinkedList& rhs);
    ~LinkedList();

public:
    void popBack(); // O(n)
    void pushBack(const T& el); // O(1)

    void popFront(); // O(1)
    void pushFront(const T& el); // O(1)

    // Should be rewritten with iterators so complexity falls to O(1)
    void insertAfter(const T& data, const T& el);
    void removeAfter(const T& data);

    //const iterator find(const T& data);

    const T& front() const;
    T& front();

    const T& back() const;
    T& back();

    bool empty() const;
    size_t getSize() const;

    void printElements(std::ostream& os) const ;

private:
    void free();
    void copy(const LinkedList& rhs);


private:
    struct node {
        T data;
        node* nextNode;

        node(const T& nData, node* nNodePtr = nullptr):
            data(nData), nextNode(nNodePtr){
        }
    };

private:
    node* frontNode;
    node* backNode;
    size_t size;

};

template <typename T>
LinkedList<T>::LinkedList(): frontNode(nullptr), backNode(nullptr), size(0){
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs): frontNode(nullptr),
    backNode(nullptr), size(0){
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
void LinkedList<T>::free(){
    node* it;
    while(frontNode != nullptr){
        it = frontNode;
        frontNode = frontNode->nextNode;
        delete it;
    }
    frontNode = nullptr;
    backNode = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& rhs){
    if (rhs.empty())
        return;
    try {
        frontNode =  new node(rhs.frontNode->data);
        node* thisIt = frontNode;
        node* otherIt = rhs.frontNode;
        while(otherIt->nextNode != nullptr){
            otherIt = otherIt->nextNode;
            thisIt->nextNode = new node(otherIt->data);
            thisIt = thisIt->nextNode;
        }
        backNode = thisIt;
    } catch (std::bad_alloc){
        std::cerr << "Bad alloc in copy function!" << std::endl;
        free();
        throw;
    }
    size = rhs.size;
}

template <typename T>
const T& LinkedList<T>::front() const {
    return frontNode->data;
}

template <typename T>
T& LinkedList<T>::front() {
    return const_cast<T&>(
        static_cast< const LinkedList& >(*this).front()
    );
}

template <typename T>
const T& LinkedList<T>::back() const {
    return backNode->data;
}

template <typename T>
T& LinkedList<T>::back() {
    return const_cast<T&>(
        static_cast<const LinkedList&>(*this).back()
    );
}

template <typename T>
size_t LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return size == 0;
}

template <typename T>
void LinkedList<T>::printElements(std::ostream& os) const {
    os << "Content of linked list: " << "\n";
    os << "{ ";
    node* it = frontNode;
    if (size == 0){
        os << "{ }" << "\n";
    }
    while (it->nextNode != nullptr) {
        os << it->data << ", ";
        it = it->nextNode;
    }
    os << it->data << " }" << "\n";
}

template <typename T>
void LinkedList<T>::pushFront(const T& el){
    node* newFront = new node(el, frontNode);
    frontNode = newFront;
    if (empty()) {
        backNode = frontNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::pushBack(const T& el) {
    if(empty()){
        pushFront(el);
        return;
    }
    backNode->nextNode = new node(el);
    backNode = backNode->nextNode;
    size++;
}

template <typename T>
void LinkedList<T>::popFront(){
    if (empty()){
        throw std::logic_error("The list is empty");
    }
    if (size == 1){
        free();
        return;
    }
    node* temp = frontNode;
    frontNode = frontNode->nextNode;
    delete temp;
    temp = nullptr;
    size--;
}

template <typename T>
void LinkedList<T>::popBack(){
    if(empty()){
        throw std::logic_error("Poping in a empty list!");
        return;
    }
    if(size == 1){
        free();
        return;
    }
    node* it = frontNode;
    while (it->nextNode != backNode){
        it = it->nextNode;
    }
    delete backNode;
    backNode = it;
    backNode->nextNode = nullptr;
    size--;
}

template <typename T>
void LinkedList<T>::insertAfter(const T& data, const T& el){
    if (empty()){
        pushFront(el);
        return;
    }
    node* it = frontNode;
    while( (it->data != data) && (it != nullptr)){
        it = it->nextNode;
    }
    if (it == nullptr){
        throw std::logic_error("No such insert data found!");
        return;
    }
    if (it == backNode){
        pushBack(el);
        return;
    }
    node* newNode = new node(el, it->nextNode);
    it->nextNode = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::removeAfter(const T& data){
    if (empty()){
        throw std::logic_error("The list is empty");
        return;
    }
    node* it = frontNode;
    // Case data is the first
    if (it->data == data){
        popFront();
        return;
    }
    //All other cases
    while ( (it != nullptr)&&(it->data != data)){
        it = it->nextNode;
    }
    // Not found
    if (it == nullptr){
        throw std::logic_error("No such data found!");
        return;
    }
    node* toBeDeleted = it->nextNode;
    it->nextNode = it->nextNode->nextNode;
    delete toBeDeleted;
    size--;
}


#endif
