#include <iostream>
#include <cstring>

using namespace std;

void sol1() {
    char buffer[32] = "test";

    while (strcmp(buffer, ".") != 0){
        cin >> buffer;
        cout << buffer << endl;
    }

}

void sol2(){
    char sym = '1';
    char word[64];
    int i = 0;
    while (sym != '\0'){
        cin >> sym;
        word[i] = sym;
        i++;
    }
}

int main(){


}
