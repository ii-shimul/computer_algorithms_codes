#include <bits/stdc++.h> // include all header files
using namespace std;

vector<pair<int, int>> graph[100]; // declare an array of vectors to represent the graph (adjacency list) with node-weight pairs, max 100 nodes
int n, e; // declare global variables n (number of nodes) and e (number of edges)
int visited[100]; // declare array to mark nodes as visited during DFS, size 100

// function to perform iterative DFS and print the traversal order
void DFS(int start) {
  cout << start << " "; // output the starting node
  visited[start] = 1; // mark the starting node as visited
  stack<int> stk; // initialize a stack to manage nodes for DFS
  stk.push(start); // push the starting node onto the stack

  while (!stk.empty()) { // run a loop until the stack is empty
    int top = stk.top(); // get the top node from the stack
    bool pushed = false; // initialize flag to track if a new node was pushed

    for (int i = 0; i < graph[top].size(); i++) { // run a loop through all neighbors of the top node
      int node = graph[top][i].first; // get the neighbor node from the pair (ignoring weight)
      if (!visited[node]) { // if the neighbor has not been visited
        cout << node << " "; // output the neighbor node
        visited[node] = 1; // mark the neighbor as visited
        stk.push(node); // push the neighbor onto the stack for further exploration
        pushed = true; // set flag to true since a node was pushed
        break; // exit the loop after pushing one unvisited neighbor
      }
    }

    if (!pushed) { // if no unvisited neighbors were found
      stk.pop(); // remove the top node from the stack
    }
  }
}

// main function to execute the DFS traversal on a directed graph
int main() {
  cin >> n >> e; // input the number of nodes n and edges e
  int u, v, w; // declare variables u, v, and w to store edge endpoints and weight
  for (int i = 0; i < e; i++) { // run a loop to input e edges
    cin >> u >> v >> w; // input the source node u, destination node v, and weight w
    graph[u].push_back({ v, w }); // add the pair (v, w) to the adjacency list of u (directed edge)
  }

  DFS(1); // call DFS starting from node 1 to traverse and print the graph
}