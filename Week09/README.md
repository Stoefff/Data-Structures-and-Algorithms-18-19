### Seminar 28.11.18

## Hash
Have 3 different definition:
* Hash table
* Hash function
* Hash code

### Hash function
Takes and element of an array and creates and int, which corresponds to
the index of the hash table

### Collisions
If a two different elements go to the same place in the same table
a collision is present

### Search
The function takes a key, hashes it and look in the hash table

**If most wanted operation is search and `do not care
even once about the order` we should use a hash**

### Adding an element
The function take a key and a data, hashes it and puts it in the table

### Removing an element
Same as before, takes a key hashes it and removes the data in the hash

### Complexity in a perfect word:
* get(key) - O(1)
* insert(key, data) - O(1) amortized
* removing(key) - O(1) amortized

### Hash functions examples
* if we have an array with n elements, the hash function is (key % n),
but resizing is a problem, a lot of collisions
* The hashcode is the product of the key and big prime number

**Never write hash function on our own**

### Collision handling:
* Open address
* Separate chaining hash

### Open address hashing - затворено хеширане
* Linear probing - if a address is taken start going down by a step n, until we
see a open address, n should be coprime (взаимно просто) with the size of the array
* Double hashing - if a collision is present we do a nested table for the
collided element with a second different hash functions

### Separate chaining hash
So instead of storing just keys, the hash table is an array of listed list
or tree and put the key in it

### Advance hashing algorithms for research
* CRC
* MD5
* SHA

### Lecture - 28.11.18

## Hashes

### Types of hashing algorithm:
* Secure hashing algorithm
* Normal hashing algorithm

### Perfect hash functions definition
* For the same input the f should the same output
* For two different inputs the output should be 2 different values

### Normal hashing function
Once we hash a key to a value, we can not reconstruct the key from the value

### Good hashing function:
Balances the hash so good that no chain has more than 5 elements

### In STL
* Hash is called an unordered set
* Tree is ordered set
