#ifndef __CONGA__HEADER
#define __CONGA__HEADER

#include "Student.h"
#include "iostream"


class Conga{
public:
    Conga();
    Conga(const Conga& rhs);
    Conga& operator=(const Conga& rhs);
    ~Conga();

    void pushFront(const char* name, const char* uni);
    void pushBack(const char* name, const char* uni);

    void popFront();
    void popBack();

    void appendWith(Conga& other);
    Conga removeByName(const char* name);

    const Student& front() const;
    Student& front();
    const Student& back() const;
    Student& back();

    bool empty() const;
    size_t getSize() const;
    void print(std::ostream& os) const;

private:
    void free();
    void copy(const Conga& rhs);

private:
    struct node{
        Student student;
        node* nextNode;
        node* prevNode;

        node(const Student& st, node* prevNode = nullptr, node* nextNode = nullptr):
            student(st), nextNode(nextNode), prevNode(prevNode){
        }
    };

private:
    node* frontNode;
    node* backNode;
    size_t size;
};

#endif
