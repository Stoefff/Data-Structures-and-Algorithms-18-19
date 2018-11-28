### Seminar - 21.11.18

### Object* vs Object**

### Linking problems from the exam
It is a linking problem when we write definition of normal functions in
the header file  
Only in this scenario it is ok to do this:
* inline functions - the compiler handles them well
* template functions - because this are not function but a set of functions.  

Normal functions could be included multiple times.


### Priority queue with a heap
Complexity - O(n)

## Binary search tree - BST
* Most of its operations are with complexity O(log n) - best case  
* We have a root
* Operations are good with recursion by picking a new root

### Adding elements
We start from the root and compare the value of the root with the
value of the the node we what to add. If the the value is bigger that
the root we go in the right. If is not we go to the left. We do this
recursively until we meet a leaf/end

### Searching elements
Same as adding elements

### Removing elements -
2 cases when the element:
* Is a leaf - same as before
* Has one child:
We switch this element with its child (left or write)
and then delete the element
* Has two child:
We what to delete the root of the BST or BST subtree. We swap
the root with either the most right of the left subtree or
the most left on the right subtree. These 2 elements are
with the closest value to the value of the root

### Degenerate tree - linked list
When the trees looks like a linked list - every node has only
one children. This way the tree becomes a slightly more complex
linked list. In this case the operations become with

### Tree traversal
6 ways - permutation of left root right:
* Left Root Right - prints sorted array - the lowest is first
* Root Left Right - possible permutation
* Right Root Left - prints sorted array - the biggest is first
* Other 3 possible permutation are not so special

### Trie tree - syntax tree, a node could have many children

### Self balancing trees
* Red black tree
* AVL tree

### Balanced tree / B tree

### Lecture - 21.11.18

### Heap implementation

**Теорема на МЕИ-то / Теорема на Семерджиев:  
Ако България е област пълна с идиоти, то  
МЕИ-то е точка на сгъстяване.

Докзателство на теоремата:
БОО избираме елемент от техническия  
Този елемент винаги е идиот  
=> теоремата е доказана**

### Allocator
So it is a good practice to have a class just for handling the allocation
of nodes or just all data

### Problem with recursion in the trees
Recursion will break for big trees, because the static stack will overflow.
In this case we write out own dynamic stack and use it. Many optimization
tricks are avaliable, see the
[The Repo of Semergiev](https://github.com/semerdzhiev/sdp-samples)
