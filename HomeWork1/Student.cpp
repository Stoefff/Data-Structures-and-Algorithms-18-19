#include "Student.h"
#include <cstring>

/*
Student::Student(): name(nullptr), uni(nullptr){
}
*/

Student::Student(const char* nName, const char* nUni):
    name(nullptr), uni(nullptr){
    if (!validUni(nUni)){
        throw std::invalid_argument("No such uni allowed");
    }
    name = new char[strlen(nName)];
    strcpy(name, nName);
    uni = new char[strlen(nUni)];
    strcpy(uni, nUni);
}

Student::Student(const Student& rhs): name(nullptr), uni(nullptr){
    copy(rhs);
}

Student& Student::operator=(const Student& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Student::~Student(){
    free();
}

void Student::free(){
    delete[] name;
    uni = nullptr;
    delete[] uni;
    uni = nullptr;
}

void Student::copy(const Student& rhs){
    name = new char[strlen(rhs.name)];
    strcpy(name, rhs.name);
    uni = new char[strlen(rhs.uni)];
    strcpy(uni, rhs.uni);
}

bool Student::validUni(const char* uni) const{
    if (!strcmp(uni, "fmi") &&
        !strcmp(uni, "ty") &&
        !strcmp(uni, "unss")) {
        return false;
    }
    return true;
}

void Student::print(std::ostream& os) const {
    os << "(" << name << ", " << uni << ")";
}

bool Student::isFriend(const Student& other) const {
    if (!strcmp(uni, "fmi")){
        if((!strcmp(other.uni, "unss")))
            return false;
        else
            return true;
    }
    if (!strcmp(uni, "tu")){
        if((!strcmp(other.uni, "fmi")))
            return false;
        else
            return true;
    }
    if (!strcmp(uni, "unss")){
        if((!strcmp(other.uni, "tu")))
            return false;
        else
            return true;
    }
    // The line below could not be reached because
    // the input is validated, but complier does not know that
    return false;
}

bool Student::sameNames(const char* name) const {
    return (!strcmp(this->name, name));
}
