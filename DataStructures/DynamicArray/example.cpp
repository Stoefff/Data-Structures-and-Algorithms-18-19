#include "dynamicArray.hpp"

using namespace std;

int main() {
    DynamicArray<int> arr;
    DynamicArray<int> otherArr (6);

    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.pushBack(4);
    arr.pushBack(5);
    arr.popBack();
    arr.printElements(cout);

    cout << arr[3] << endl;
    arr[3] = 69;
    cout << arr[3] << endl;
    arr.printElements(cout);

    cout << arr.find(2) << endl;

    arr.insertAt(2, 41);
    arr.printElements(cout);

    arr.removeAt(2);
    arr.printElements(cout);

    otherArr = arr;
    otherArr.printElements(cout);

    DynamicArray<int> arr2 = arr;
    arr2.printElements(cout);


    cout << "Hello World!" << endl;
    return 0;
}
