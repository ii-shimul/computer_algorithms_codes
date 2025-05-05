#include <bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visited[1001];
int n, e;

void BFS(int start) {
  visited[start] = 1;
  cout << start << " ";
  queue<int>q;
  q.push(start);

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (visited[i] == 0 && graph[x][i] != 0) {
        visited[i] = 1;
        cout << i << " ";
        q.push(i);
      }
    }
  }
}

int main() {
  cin >> n >> e;
  int u, v;
  for (int i = 0; i < e + 1; i++) {
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  BFS(1);

}