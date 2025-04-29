#include<bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001];
int n, e;

void DFS(int start) {
  visited[start] = 1;
  cout << start << " ";
  for (int j = 1; j <= n; j++) {
    if (visited[j] == 0 && graph[start][j] != 0) {
      visited[j] = 1;
      DFS(j);
    }
  }
}

int main() {
  cin >> n >> e;
  int u, v;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  DFS(1);
}