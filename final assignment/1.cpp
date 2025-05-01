#include <bits/stdc++.h> // include all header files
using namespace std;

vector<pair<int, int>> graph[1001]; // declare an array of vectors to represent the graph (adjacency list) with node-weight pairs, max 1001 nodes
int visited[1001]; // declare array to mark nodes as visited during DFS, size 1001
int n, e; // declare global variables n (number of nodes) and e (number of edges)
stack<int> ans; // declare global stack to store the topological order

// function to perform DFS and build the topological order
void dfs(int start) {
  visited[start] = 1; // mark the starting node as visited
  for (int i = 0; i < graph[start].size(); i++) { // run a loop through all neighbors of the start node
    int node = graph[start][i].first; // get the neighbor node from the pair (ignoring weight)
    if (visited[node] == 0) { // if the neighbor has not been visited
      dfs(node); // recursively call dfs on the unvisited neighbor
    }
  }
  ans.push(start); // push the current node onto the stack after exploring all its neighbors
}

// main function to compute and output the topological sort of a directed graph
int main() {
  cin >> n >> e; // input the number of nodes n and edges e
  int u, v, w; // declare variables u, v, and w to store edge endpoints and weight
  for (int i = 1; i <= e; i++) { // run a loop to input e edges
    cin >> u >> v >> w; // input the source node u, destination node v, and weight w
    graph[u].push_back({ v, w }); // add the pair (v, w) to the adjacency list of u (directed edge)
  }

  for (int i = 1; i <= n; i++) { // run a loop through all nodes from 1 to n
    if (visited[i] == 0) { // if the current node has not been visited
      dfs(i); // call dfs to explore and process this node
    }
  }

  while (!ans.empty()) { // run a loop until the stack is empty
    cout << ans.top() << " "; // output the top node from the stack (part of topological order)
    ans.pop(); // remove the top node from the stack
  }
  cout << endl; // output a newline after printing all nodes
}