### Seminar - 19.12.18

### Dikstra algorithm
Finds the shortes path form a vertex to all others
* Does not work with negative values for weights
* Time complexity - O(n log n) - with a heap, or a `fibonachi heap`
```pseudocode
1  function Dijkstra(Graph, source):
2
3      create vertex set Q
4
5      for each vertex v in Graph:             // Initialization
6          dist[v] ← INFINITY                  // Unknown distance from source to v
7          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
8          add v to Q                          // All nodes initially in Q (unvisited nodes)
9
10      dist[source] ← 0                        // Distance from source to source
11      
12      while Q is not empty:
13          u ← vertex in Q with min dist[u]    // Node with the least distance
14                                              // will be selected first
15          remove u from Q
16          
17          for each neighbor v of u:           // where v is still in Q.
18              alt ← dist[u] + length(u, v)
19              if alt < dist[v]:               // A shorter path to v has been found
20                  dist[v] ← alt
21                  prev[v] ← u
22
23      return dist[], prev[]
```

### Belman-Ford algorithm
Finds all the shortest path from a vertex to all others
* works with all numbers for weights
* Does not work with loops with only negative numbers
* Time complexity - O(n^3)

### Floyd-Warshall
Finds the shortest path form all vertices to all other vertices
* Work with all numbers
* Finds loop only with negative number
* Time complexity - O (n^3)