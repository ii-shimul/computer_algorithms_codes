#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visited[1001];
int n, e;
int visitedCount = 0;

void DFS(int start) {
  visited[start] = 1;
  visitedCount++;
  stack<int> stk;
  stk.push(start);

  while (!stk.empty()) {
    int x = stk.top();
    stk.pop();

    for (int j = 0; j < graph[x].size(); j++) {
      int node = graph[x][j];
      if (visited[node] == 0) {
        visited[node] = 1;
        visitedCount++;
        stk.push(node);
      }
    }
  }
}

bool isTree() {
  if (e != n - 1) {
    return false;
  }

  memset(visited, 0, sizeof(visited));
  visitedCount = 0;

  DFS(1);

  return (visitedCount == n);
}

int main() {
  cin >> n >> e;
  int u, v;

  for (int i = 1; i <= e; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  if (isTree()) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}