#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100];
int n, e;
int visited[100];

void DFS(int start) {
  cout << start << " ";
  visited[start] = 1;
  stack<int> stk;
  stk.push(start);

  while (!stk.empty()) {
    int top = stk.top();
    bool pushed = false;

    for (int i = 0; i < graph[top].size(); i++) {
      int node = graph[top][i].first;
      if (!visited[node]) {
        cout << node << " ";
        visited[node] = 1;
        stk.push(node);
        pushed = true;
        break;
      }
    }

    if (!pushed) {
      stk.pop();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> e;
  int u, v, w;
  for (int i = 0; i < e; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({ v, w });
  }

  DFS(1);
}
