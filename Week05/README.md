### Seminar - 31.10.18

## Iterators
Gives an abstraction for a certain data structure  
It should be written because the STL algorithms use iterators

### STL requirements
Vanaka said that in order for STL to use the iterator of our data structure
as a abstraction, we should `typedef` some types in order for the lib
to understand us

### 5 types of iterators
* Input iterator
* Output iterator
* Forward iterator
* Bi-Directional iterator - for double linked lists
* Access iterator - random access for arrays

## Stack - lifo
Intended for limited access tasks  
Tasks like sorting or traversal are not supported

### Basic operations all with complexity O(1)
* peak
* pop
* push

### Implementation
* With array
* With list

## Queue - fifo
Same shit different day

### Implementing with list
Just switching the list upside down meaning:
We delete at the front and add the back

### Implementing with static array
We just use cyclic array

#### Interesting syntax:
```c++
template <typename T, size_t N>
static_queue<int, 10>
```
### The thing about the fucked up list method:
Casting a non-cost object to a const object

### Template stacks and queues
It should be inited with the type of container it should be implemented with


### Lecture - 31.10.18

## Stack and Queue

### Inline function
A smart macros - instead of creating a stack procedure it moves the code of
the function to the place it is called smartly. General use:
* Small functions
* Flexing on the templates

### Sentinels
Instead of using nullptr for the invalid elements we designate element to
catch these states and we call it a sentinel. In theory is seem very nais
but in practice this pattern it could fuck many of the functionality of methods  
Some of the useful cases: It makes us skip comparisons

### How to make a priority sensitive calculator using 2 stacks
We make stacks:
* Containing the operators
* Containing the arguments of the operators

We traverse the equation and if we read a operation which is with higher
or same priority compared to the current top operation in the stack, we add it
to the stack and add the arguments in the other  
If we read a operation with lower priority we execute the operations in the
stacks and write the result in the stack as arguments of the operation

#### Shunting yard - good example for stack
