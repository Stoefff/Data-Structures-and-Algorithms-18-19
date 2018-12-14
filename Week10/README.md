### Seminar - 05.12.18

### Check std::pair

### Map
* unordered map - just a hash
* ordered map - just a RB tree

### Set
* unordered set - hash
* ordered set - RB tree

### Multi-set and multi-map

## Graphs
G = (V, E), G is a graph, V is a set of vertices, set of
edges  
|V|  = n, |E| = m

### Way of representing the graphs
* Matrix of neighbors  
* List of children
* List of edges 

### List of edges
* Memory complexity - O (m)
* search - O(m)
* add - O(m) / could fall to O(log(m) if it's a tree)
* remove O(m) / could fall to O(log(m))
* Find all adjacent - O(m)
* BFS/DFS complexity - O(n*m)
We use it when the graph the is small meaning
it has only a few edges and m << n

### Matrix of neighbor
* Memory - O(n^2)
* search - O(1)
* add - O(1)
* remove - O(1)
* Find all adjacent - O(n)
* BFS/DFS complexity - O(n^2)
We use this when the the graphs is big meaning is almost full

### List of children
Represented as a unordered map(hash), where the key is an edge, and the data
is a list of all the children
* Memory - O(2 m)
* search - O(d), where d is the biggest degree of all the vertices
* add - O(di), d of the current vertices i
* remove - O(di), d of the current vertices i
* Find all adjacent - O(1)
* BFS/DFS complexity - O(n+m)
We use this when we need to do operations with the
children of a certain vertex many times, but big overhead

### Lecture - 05.12.18

## Allocators
An abstraction for managing predefined heap space


## Graphs

### Useful algorithms:
* Sparse table
* sparse array
* sparse tree ?
