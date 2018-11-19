#include "Student.h"
#include "../../DataStructures/DynamicArray/dynamicArray.hpp"

void sortByGrade(DynamicArray<Student> students) {
    // Works only with zeros and inits all other after it
    size_t countArrSize = 7;
    int countArr[7] = {0, };

    size_t arrSize = students.getSize();
    DynamicArray<Student> sortedArr = arrSize; //Same as (arrSize)

    for(int i = 0; i < arrSize; i++){
        size_t temp = 0;
        temp = students[i].grade;
        countArr[temp]++;
    }
    for(int i = 1; i < countArrSize; i++){
        countArr[i] = countArr[i-1] + countArr[i];
    }
    for(int i = 0; i < arrSize; i++){
        size_t temp = 0;
        temp = students[i].grade;
        sortedArr[countArr[temp]] = students[i];
    }
    students = sortedArr;
}

int main(){

    return 0;
}
