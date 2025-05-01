#include<bits/stdc++.h> 
using namespace std;
int graph[1001][1001];
int visited[1001];
int n, e;

void BFS(int start) {
  visited[start] = 1;
  cout << start << " ";
  queue<int>Q;
  Q.push(start);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int j = 1; j <= n; j++) {
      if (visited[j] == 0 && graph[x][j] != 0) {
        visited[j] = 1;
        cout << j << " ";
        Q.push(j);
      }
    }
  }

}
int main() {
  cin >> n >> e;
  int u, v, w;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v >> w;
    graph[u][v] = w;
    graph[v][u] = w;
  }
  BFS(1);
  return 0;

}