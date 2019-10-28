#ifndef __DANCE__FLOOR__HEADER
#define __DANCE__FLOOR__HEADER

#include "Conga.h"

class DanceFloor {
public:
    DanceFloor();
    DanceFloor(const DanceFloor& rhs);
    DanceFloor& operator=(const DanceFloor& rhs);
    ~DanceFloor();

    void pushBack(const Conga& el);
    void popBack();

    void removeAt(const size_t index);

    void merge(const size_t index1, const size_t index2);

    size_t getSize() const;
    size_t getCap() const;
    bool empty() const;

    const Conga& operator[](const size_t index) const;
    Conga& operator[](const size_t index);

    void print(std::ostream& os) const;

private:
    void free();
    void copy(const DanceFloor& rhs);
    void resize(const int newSize = -1);

private:
    Conga* arr;
    size_t size;
    size_t cap;
};

#endif
