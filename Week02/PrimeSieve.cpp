// Yulian Stoev - 45 384

// 1613 2143 4493 5003 9293
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::find;

#define prime false
#define compo true
//typedef unsigned int uint;
// The COUNT of the numbers from 0 to 10000 is 10001
const uint target = 10001;

//Sieve of Eratosthenes
void calculatePrimes(bool* numbers){
    // Not prime, but not composite either
    numbers[0] = true;
    numbers[1] = true;
    // Optimization for the calculation - All composite numbers after
    // the barrier are already found from a number before the barrier
    uint barrier = sqrt(target)+1;
    for(uint i = 2; i <= barrier; i++)
        if (numbers[i] == prime)
            for (uint j = i * i; j < target; j += i)
                numbers[j] = compo;
}

//Slow, refactor later for the flex
vector<uint> getPrimeFactors(uint x, bool* primeNumbers){
    vector<uint> primeFactors;
    uint barrier = x / 2;
    for(uint i = 0; i < barrier; i++)
        if ( (primeNumbers[i] == prime) && ((x % i) == 0))
            primeFactors.push_back(i);
    return primeFactors;
}

/*
void cleanFifth (vector<uint>& factors){
    vector<uint>::iterator it = factors.begin();
    // The fifth element could only be in first 3 positions at the array
    for(uint i = 0; (i < 3) && (it != factors.end()); i++, it++){
        if (*it == 5){
            factors.erase(it);
            return;
        }
    }
}
*/

int main(){
    bool* numbers = new bool[target]{prime, };
    calculatePrimes(numbers);
    for(uint i = 0; i < target; i++){
        if ( (numbers[i] == prime) && ( (i % 10) == 3)){
            if (numbers[i+2] == prime)
                continue;
            vector<uint> factors = getPrimeFactors(i+2, numbers);
            //cleanFifth(factors);
            vector<uint>::iterator it = find(factors.begin(), factors.end(), 5);
            if (it != factors.end())
                factors.erase(it);
            for (uint j = 0; j < (factors.size() - 1); j++){
                // Why it seg faults without this ???
                if (factors.size() <= 1)
                    break;
                if ((factors[j] + 2) == factors[j + 1]){
                    cout << i << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
    delete[] numbers;
    return 0;
}