### Seminar - 14.11.18

## Complex Sorting algorithms

### Quick Sort
```c++
qsort(arr, l, r){
    p <- pivot(l, r);
    p1 <- partition(arr, p);
    qsort(arr, l, p1);
    qsort(arr, p1, r);
}
```
### The tricky part is pick a good pivot
General case is that we choose the pivot to be the element in the middle
The good case is to use the `3 medians algorithm` which takes the first,
the last, the middle and makes the pivot its average

### Uses
* General case with random data - very good
* Worst case is n^2 time complexity

### Quick tree
Just like the quick sort but with 3 partitions, instead of 2

### Complexity
* Time - n logn
* Memory - log n, because the recursion uses new stack frames

### The algorithm is not stable and not adaptive

### Big hidden problem of the algorithm
People does not suspect the memory complexity to be this high

### Merge sort
```c++
//Bottom up merge sort
merge_sort(arr, l, r){
    mid = (l + r)/2;
    f <- merge_sort(arr, l, mid);
    s <- merge_sort(arr, mid, r);
    merge(f, s); // Combining the sorted redici
}
```

### Complexity
* Time - n logn - all cases
* Memory - n for the array used for swapping

### Stability and Adaptivity
Yes, can be written to be stable, but **Not** adaptive

### Tim Sort - same shit but more tarikatsko

### Heap sort

### Definition of heap (пирамида)
* Binary balance tree with h height
* Every node is with bigger value than its child nodes
* Nodes on the same level are with left priority - small are on the left
```c++
heap_sort(arr, s){
    for(i <- (n/2)+1; i > 0; i--){ //build heap function
        sift(arr, i, )
    }
    for(i <- n, i > 1, i--){
        swap(arr[1], arr[i]); // n
        sift(arr, 1, n - (n - i)); // Restoring the heap log n
    }
}
```
### Complexity
* time - n log n
* memory - 1


### Stability and Adaptivity
* Stable
* Not adaptive

### Sorting arrays in the linked list
Only insertion and merge sort work

### These algorithms does not only use number
The std::sort functions could sort objects, if the objects have predefined
operators for comparisons and we should pass a functor on how the objects
compare themselves

## Sorting without comparison

### Counting sort
Just making a new array with value of the indexes that represent the values
in the array, if

### Complexity
* Time - 3n
* Memory - depends on the difference between the min and max elements

### Tarikat sort - Radix sort and Bucket sort
Using the bit values of the value of the array, comparing the bit for like:
puts in the bucket the elements the same value for the 3rd digit, this bucket
we split in buckets for the 2nd digit

### MSD Radix - most significant first radix
For comparing string like splitting the string the same way as explained above

Complexity:
* Time log of the length of the biggest memory
* Memory

## Array search

### Binary search in 7 of the major languages actually have a bug

### Jump search
Just an advance binary search
Best case for the step - square root of n

### Lecture - 14.11.18

## Trees
Very good structure, most of its complexity is log(n), or something with it

### Order of array searching
* pre-Order - the root is searched before the left and then right
* in-Order - the root is searched between the left and the right
* after-Order - the root is searched after the left and then right

### Izrodeno tree
Imagine it as just a stick xDDD

### Balanced tree
* Balanced criteria:
** Balanced by height - for every conduit we have max 1 node in the height
difference with all other conduits
** Balanced by weight - the 2 child tree of a root, should have max 1 node in
difference of number of nodes in the tree

### Balanced by height is a tricky one

### Ways of coding a tree:
* Like a list
* With array of predecessors level, containing array and pointer to next level
* Just with a array: a node with index i has a children with indexes of 2i+1
and 2i + 2

### Locality
In the general case the locality is bad. but when we use the array implementation
of the tree, when we use close to root nodes, locality is ok

### Problem with the just array implementation
* We should think

### Full tree
Only the last level of the tree is not full  
It it represented as a liner array very easily

### PushBack to the tree
Makes the tree unbalanced and izrodeno

### Basic tasks with trees
* Moving elements from a sorted array to a tree
* Moving elements from a tree to a sorted array  

### Good way to store info in threes like Vanaka said
* The smaller element is always in left
* The bigger element is always in right
This way we know that min element is the far left and
the biggest is the far right

### Advanced data structures
AVL, red-black trees, B-trees

**The aim is all trees to be binary balanced podredeni**

### Binary heap
Binary tree with O(1) access and O(log n) add and delete because
it uses the
