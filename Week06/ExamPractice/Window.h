#ifndef __Window__HEADER
#define __Window__HEADER

#include <string>
#include <ctime>

using std::string;

class Window{
private:
    struct tab{
        string url;
        time_t timestamp;
        tab* nextTab;

        tab(const string& newUrl, tab* newNextTab = nullptr){
            url = newUrl;
            nextTab = newNextTab;
            timestamp = time(NULL);
        }
    };

private:
    tab* frontTab;
    tab* backTab;
    size_t size;

public:
    Window();
    Window(const Window& rhs);
    Window& operator=(const Window& rhs);
    ~Window();

    void pushBack(const string& el);
    void handleTab(const string& el);

private:
    void free();
    void copy(const Window& rhs);
    void removeAfterLast(const tab* tab);
    tab* findTab(const string& el);
};

#endif
