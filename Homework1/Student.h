#ifndef __STUDENT__HEADER
#define __STUDENT__HEADER

#include <iostream>

//add to lower function
class Student{
public:
    Student() = delete;
    Student(const char* name, const char* uni);
    Student(const Student& rhs);
    Student& operator=(const Student& rhs);
    ~Student();

    void print(std::ostream& os) const;
    bool isFriend(const Student& other) const;
    bool sameNames(const char* name) const;

private:
    void free();
    void copy(const Student& rhs);

    bool validUni(const char* uni) const;

private:
    char* name;
    //Shoud be ENUM, refactor this later
    char* uni;
};

#endif
