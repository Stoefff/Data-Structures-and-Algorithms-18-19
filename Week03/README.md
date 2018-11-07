### Vasi's and Vanaka's seminar - 17.10.18

## Complexity
 2 basic types of complexity:
 * Complexity in terms of memory
 * Complexity in terms of time  

 ## Big "O" notation or how to grade complexity
 A function which compares other functions  
 O(f) < 0(n^2), where f is selection sort
In coders terms we ignore the sum of constants

The Big "O" notation graph:
![interesting](https://www.coengoedegebure.com/content/images/2017/10/bigochart.gif)
Where x is the number of input data and y is the time passed  

**Usually programmers use 2 instead of the `e` constant, where talking about
the exponential and the logarithm**

### Abstract data structures
Basic things to do:
* Searching
* Adding
* Removing
* Access to elements

## Dynamic array (vector)

### Complexity of adding an element:
* `push_back`: O(1) - Amortizated constant, because in so e cases we should resize
* `insert_at`: O(n)

### Complexity of removing an element:
* `pop_back`: O(1) - Constant if removing is done with a swap and the array is
not wanted sorted
* `remove_at`: O(n) at the general case, best case is O(1)

### Complexity of searching:
* `general case`: 0(n) - linear search
* `best case`: O(log n) - binary search


### Difference between std::vector and std::array
Vector is a class implementing dynamic array and Array is a class implementing
an array with a constant length, C style

**Inline function - instead of calling a function, it replaces the code of
the function where it is called**

**Template function and classes have a big problem: if a template function/class
does not have an instance in the code, it wont even be tried to be compiled. This
means if we dont have a instance we couldn't even check if the code is good**

### Semerdzhiev lecture - 17.10.18

Some new feature about dynamic arrays:

### Implementing a reserve function
Used for faster resizing and decreasing the complexity of the resize function  
Instead of resizing every time when a new out-of-bound element should be added,
we could resize once with the needed size of all elements needed to be added in
one operation, meaning if our array currently have 4 elements and we need to add
1000 new elements, it would be slow to use the normal resize. Instead we use a
function which chooses how and how much to resize with a single function call.

### Tuning the `operator []` with a proxy object - not STL implementation
The operator[] normally have two different function:
* `cout << arr[1];` - access to the element of the array
* `arr[1] = 4;` - access and operator =

So we could use a proxy object the array, just to difference between these
2 different operations

### Locality - very important to be good in order for a good algorithm to work fast
Good example is the difference when traveling in a 2D array represented as a 1D
array, by rows and then columns and by columns then rows. When going by rows and
then columns locality plays a big role and speeds the access of elements, because
of caching  

General cases, keep in mind in **always** depends of the specific situation
* Arrays - good locality
* Linked lists - bad locality
* Trees - bad locality  

### Linked list characteristics:
* Adding/Removing/Accessing element
** Close to the start/end: O(1)
** Randomly at the general case: O(n)
** Randomly if we know where exactly to add/remove it meaning we should
know the indexes of the list: O(1)

* Locality
** When the liked list isn't very used or messed with - good
** When we start to add

**Two good use cases of the linked list:
* When the use case is good
* Using it as a helper structure in other data structure**

### Types of linked list:
* Normal linked list
* Double linked list
* Cyclic linked list
* Mindfuck linked list

### Practice - 22.10.18

## Closures an lambda expression
