## Vasi's and Paco's practice - 08.10.18

### Actually the iterator is a type of proxy to this structure

### The "good" question
```c++
Obj a(...);
Obj b = a;
```
Here b will call its copy constructor

### Unit and integration testing
* Unit testing - testing the functionality of the code
* Integration testing - testing the linking a certain code in the whole project

### Vanaka's and Vasi's seminar - 10.10.18

## Basic simple algorithms

### Hot to get sum of the digits
x = a1a2a3a4...an
a1 = 1 = log10a1

x = 1 + log10(x) - a feature of logarithms


### Euclidian algorithm - for GCD

NOD(a, b) = NOD(b , a%b)

NOD(a, 0) = a;

```c++
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b , a%b);
}
```

### Prime numbers
The simplest way to find a prime number is to run a for loop for 2 to the root of number
Why to the root of number:
Because if the number is a product of other numbers, one of them should be in 0
to root of the given number, the other from the root of the number to the given number

### Sieve of Eratosthenes

The trick with skipping numbers when deleting non prime numbers for the array
is the same prime numbers algorithms

TODO: explain it at home

### Prime numbers in the interval [a, b]
30p +- 1
30p +- 3
30p +- 7
30p +- 11
30p +- 19
30P +- 23
30p +- 29
All numbers could be represented by such a formula
and it is mathematically proven that these 8 numbers are potential prime

### Finding all permutations
Written with recursion

### Counting all combinations
With the help of the pascal triangle to count the binomen coeficient
How to calculate the indexes of the pascal triangle: with the help of recursion:
calculating the previous row to calculate the current row

### Semergiev lecture - 10.10.18

## Dynamic array (vector, container)

### Static array(non dynamic, auto array)

**The stack array is the data structure with the fastest access to a certain
element out of all structures(even hash maps) with a complexity of O(1)**

A good aspect of the static array is the locality because it gives us a certain
type of caching

### Problems with static array
When we push back an element of the array the operation is with complexity of O(1)
But when we want add an element at start of the array the operation is with
complexity of O(n) because we should shift n element

Same problem happens when we want to find a element in the array and the
complexity of the search operation is also O(n) because in most cases we
should search the whole array, just to say that the element is non existent  
The probability of find the element is lower that of not finding it

### Problems with dynamic array:
* Fragmentation
It happens because the dynamic array allows empty spaces between the allocated
memory, which by definition is called fragmentation xD

* Possible big overhead
If we want to allocate 10 001 elements, it is possible that the array have to
resize at 10 000 elements just add 1 elements and the resize allocates 20 000
elements just for 1 element needed

* Downsizing is a tricky situation
Even the std does not downsize automatically but rather gives a .shrink()
function to the programmer to use  

**Complexity of allocating dynamic array with n elements when resizing is done
with +1 operation is O(2n) -> O(n)**

**Complexity of allocating dynamic array with n elements when resizing is done
with *2 operation is O(logn)**

**Hint about HW1: write the task with 3 different containers and how each of
them is performing**
