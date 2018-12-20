#pragma once

#include "Horo.h"

class System{
public:
    System(const string& filename);
    System(const System& rhs) = delete;
    System& operator=(const System& rhs) = delete;
    ~System();

    void run();

private:
    void updateFirst(const string& name);
    void parseFile(const string& filename);

private:
    Horo horo;
    string firstDancer;
    bool isRunning;
};
