#include<bits/stdc++.h> // include all header files
using namespace std;
int graph[1001][1001]; // declare 2D array to represent the graph as an adjacency matrix, size 1001x1001
int visited[1001]; // declare array to mark nodes as visited during BFS, size 1001
int n, e; // declare global variables n (number of nodes) and e (number of edges)

// function to perform BFS and print the traversal order
void BFS(int start) {
  visited[start] = 1; // mark the starting node as visited
  cout << start << " "; // output the starting node
  queue<int> Q; // initialize a queue to manage nodes for BFS
  Q.push(start); // push the starting node into the queue
  while (!Q.empty()) { // run a loop until the queue is empty
    int x = Q.front(); // get the front node from the queue
    Q.pop(); // remove the front node from the queue
    for (int j = 1; j <= n; j++) { // run a loop through all possible nodes from 1 to n
      if (visited[j] == 0 && graph[x][j] != 0) { // if node j is unvisited and connected to x
        visited[j] = 1; // mark node j as visited
        cout << j << " "; // output node j
        Q.push(j); // push node j into the queue for further exploration
      }
    }
  }
}

// main function to execute the BFS traversal on an undirected weighted graph
int main() {
  cin >> n >> e; // input the number of nodes n and edges e
  int u, v, w; // declare variables u, v, and w to store edge endpoints and weight
  for (int i = 1; i <= e; i++) { // run a loop to input e edges
    cin >> u >> v >> w; // input the source node u, destination node v, and weight w
    graph[u][v] = w; // set the weight w for the edge from u to v in the adjacency matrix
    graph[v][u] = w; // set the weight w for the edge from v to u (undirected graph)
  }
  BFS(1); // call BFS starting from node 1 to traverse and print the graph
  return 0; // exit the program
}