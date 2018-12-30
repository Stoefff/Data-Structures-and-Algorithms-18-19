#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class List{

private:
    struct Node{
        int val;
        Node* next;

        Node(int val, Node* next = nullptr)
            :val(val), next(next){
        }
    };

public:
    List();
    List(const List& rhs);
    List& operator=(const List& rhs);
    ~List();

    void pushFront(int el);
    void pushBack(int el);

    void popFront();
    void popBack();

// STD are with it, so I wont waste time to implement, they are trivial
    void insertAfter(int el, size_t index);
    void removeAfter(size_t index);

    void print();
    void insertionSort();
    void merge();
    void mergeSort();

private:
    void copy(const List& rhs);
    void free();

private:
    Node* front;
    Node* back;
    size_t size;
};

List::List():
    front(nullptr), back(nullptr), size(0){
}

List::List(const List& rhs){
    copy(rhs);
}

List& List::operator=(const List& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

List::~List(){
    free();
}

void List::free(){
    Node* dest = front;
    while(dest != nullptr){
        front = dest->next;
        delete dest;
        dest = front;
    }
    front = nullptr;
    back = nullptr;
    size = 0;
}

void List::copy(const List& rhs){
    front = new Node(rhs.front->val);
    Node* copySource = rhs.front->next;
    Node* copyDest = front->next;
    while(copySource != nullptr){
        copyDest = new Node(copySource->val);
        back = copyDest;
        copyDest = copyDest->next;
        copySource = copySource->next;
    }
    size = rhs.size;
}

void List::pushFront(int el){
    Node* temp = new Node(el, front);
    front = temp;
    if(size == 0){
        back = front;
    }
    size++;
}

void List::pushBack(int el){
    if(size == 0){
        pushFront(el);
        return;
    }
    Node* temp = new Node(el);
    back->next = temp;
    back = temp;
    size++;
}

void List::popFront(){
    if(size == 0){
        throw std::logic_error("dafuq");
    }
    if(size == 1){
        free();
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    size--;
}

void List::popBack(){
    if(size <= 1){
        popFront();
        return;
    }
    Node* temp = front;
    while(temp->next == back){
        temp = temp->next;
    }
    delete back;
    back = temp;
    temp->next = nullptr;
    size--;
}

void List::print(){
    cout << front->val;
    Node* it = front->next;
    while (it != nullptr){
        cout << " - " << it->val;
        it = it->next;
    }
    cout << endl;
}

void List::insertionSort() {
    Node* firstIt = front;
    Node* minNode = front;
    Node* secondIt = front->next;

    List newList;
    while (firstIt != nullptr){
        while(secondIt != nullptr){
            if (secondIt->val < minNode->val){
                minNode = secondIt;
            }
            secondIt = secondIt->next;
        }

        newList.pushBack(minNode->val);

        firstIt = firstIt->next;
        minNode = firstIt;
        secondIt = firstIt->next;
    }
    free();
    copy(newList);
}

void List::merge(){

}

void List::mergeSort(){

}



int main(){
    List list;
    list.pushBack(3);
    list.pushBack(2);
    list.pushBack(4);
    list.pushBack(1);
    list.pushBack(5);

    list.print();
    cout << "Dank memes" << endl;
    //list.insertionSort();
    list.print();

    return 0;
}