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
const uint upperBarrier = 10001;

//Sieve of Eratosthenes
void calculatePrimes(bool* numbers, uint target){
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

vector<uint> getPrimeNumbers(uint target){
    bool* numbers = new bool[target]{prime, };
    vector<uint> primeNumbers;
    calculatePrimes(numbers, target);
    for (uint i = 0; i < target; i++)
        if (numbers[i] == prime)
            primeNumbers.push_back(i);
    delete[] numbers;
    return primeNumbers;
}

vector<uint> getPrimeFactors(uint x, vector<uint>& primeNumbers){
    vector<uint> primeFactors;
    uint barrier = sqrt(x)+1;
    for(uint i = 0; primeNumbers[i] < barrier; i++)
        if ( (x % primeNumbers[i]) == 0 )
            primeFactors.push_back(primeNumbers[i]);
    return primeFactors;
}

int main(){
    vector<uint> primeNumbers = getPrimeNumbers(upperBarrier);
    for(uint i: primeNumbers){
        if ( (i % 10) == 3 ){
            if (i+2 == prime)
                continue;
            vector<uint> factors = getPrimeFactors(i+2, primeNumbers);
            vector<uint>::iterator it = find(factors.begin(), factors.end(), 5);
            if (it != factors.end())
                factors.erase(it);
            for(uint j = 0; j < (factors.size() - 1); j++){
                if(factors.size() <= 1)
                    break;
                if ((factors[j] + 2) == factors[j + 1]){
                    cout << i << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}