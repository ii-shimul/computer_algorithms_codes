#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, e;
  int u, v, w;

  // matrix input
  int graph[n + 1][n + 1];
  memset(graph, 0, sizeof(graph));
  for (int i = 1; i <= e; i++) {
    cin >> u >> v >> w;
    graph[u][v] = w;
    graph[v][u] = w;
  }

  // vector input
  vector<pair<int, int>> graphV[n + 1];
  for (int i = 1; i <= e; i++)
  {
    cin>>u>>v>>w;
    graphV[u].push_back(make_pair(v, w));
    graphV[v].push_back(make_pair(u, w));
  }
  
}