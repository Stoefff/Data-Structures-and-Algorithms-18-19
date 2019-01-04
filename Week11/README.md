### Seminar - 12.12.18

## Bread First Search (BFS) and Depth First Search (DFS)
These are not actually searches but traversal

### Important numbers in the context of graphs
m - number of edges
n - number of vertices


### BFS - Търсене в широчина  
We make a partitioning (разбиванe) of the graph on levels and visit each vertices of a certain
level and then we proceed to the next level

**Complexity - O(n + m)**

### Intuition for the algorithm
We have a table of:
* Vertices
* Queue of vertices to visit
* Array of visited edges - Bool array representing if we have visited or just
pushed in the queue a certain vertices

How it works:
We step of an edge and if it's not present in Array of visited edges we push it
to the queue and add it to the AoVE

### DFS - Търсене в дълбочина
We just go down in the neighbors and recursively call the algorithm

## Finding minimal spanning tree algorithms - Prim and Kruskal

### Prim algorithm
Scanning for all paths to certain edge and adding and continuing with the
lowest weight

### Kruskal algorithm
Sorting the edges by weight. Then we start from an vertex with an edge of the
lowest weight and make it a tree. From then we traverse the sorted edges and
and makes trees from them. In the end all trees should be connected and have
one root

### Lecture - 12.12.18

### Typedef vs using
**`Using` works with template types**
```c++
template<typename T>
class Hash{
private:
    struct Dancer {
        string name;
        Dancer* leftDancer;
        bool isLeftConn;
        Dancer* rightDancer;
        bool isRightConn;

        Dancer(string name, Dancer* leftDancer = nullptr, bool isLeftConn = 0,
            Dancer* rightDancer = nullptr, bool isRightConn = 0):
            name(name), leftDancer(leftDancer), isLeftConn(isLeftConn),
            rightDancer(rightDancer), isRightConn(isRightConn){
        }
    };

    typedef  vector <list <pair <string, Dancer*>>> hashTable;

    //template<typename T>
    using h = Hash<T>
```
