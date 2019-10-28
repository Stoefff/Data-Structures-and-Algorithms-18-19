#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
using dbl = std::numeric_limits<double>;

double natLog(double number){
    double result = 0.0;
    double temp = (number-1) / number;
    for (int i = 1, counter = 0; i < 32000; i++, counter++){
        result += pow(temp, i) / i;
        cout << counter << " step: " << result << endl;
    }
    return result;
}

int main(){
    
    double number;
    cout << "Enter number, which ln should be calculated: ";
    cin >> number;
    cout.precision(dbl::max_digits10);
    cout << "ln(" << number << ") = " << natLog(number) << endl;

    return 0;
}