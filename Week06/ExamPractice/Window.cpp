#include "Window.h"

Window::Window(): frontTab(nullptr), backTab(nullptr), size(0) {
    tab* startTab = new tab("http://exam_dsa");
    frontTab = startTab;
    backTab = startTab;
    size++;
}

Window::Window(const Window& rhs):
    frontTab(nullptr), backTab(nullptr), size(0){
    copy(rhs);
}

Window& Window::operator=(const Window& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Window::~Window(){
    free();
}

void Window::free(){
    tab* destroyer;
    while(frontTab != nullptr){
        destroyer = frontTab;
        frontTab = frontTab->nextTab;
        delete destroyer;
    }
    frontTab = nullptr;
    backTab = nullptr;
    size = 0;
}
