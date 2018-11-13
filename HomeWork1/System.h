#ifndef __SYSTEM__HEADER
#define __SYSTEM__HEADER

#include "DanceFloor.h"

class System{
public:
    System();

    void run();

private:
    void appendF(const char* name, const char* uni, size_t index);
    void removeLastF(size_t index);
    void removeFirstF(size_t index);
    void removeF(const char* name, size_t index);
    void mergeF(size_t index1, size_t index2);

    size_t charToInt(const char* str);

private:
    DanceFloor floor;
    bool isRunning;
};

#endif
