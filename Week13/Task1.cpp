#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::pair;
using std::unordered_map;

typedef unsigned int  vertex;
typedef unsigned int weight;
using edge = pair<vertex, weight>;
using graph = vector<vector<edge>>;

vector<weight> path(graph& G, vertex vertex);

int main() {
    graph G;
    G[1] = {{2, 1}, {3, 11}, {4, 7}, {6, 33}};
    G[2] = {{1, 1}, {4, 3}, {6, 20}};
    G[3] = {{1, 11}, {5, 4}};
    G[4] = {{1, 7}, {2, 3}, {5, 5}};
    G[5] = {{3, 4}, {4, 5}, {6, 1}};
    G[6] = {{1, 33}, {2, 20}, {5, 1}};
    vector<weight> paths = path(G, 1);
    for(int weight : paths){
        std::cout << weight << " ";
    }
    std::cout << std::endl;
}