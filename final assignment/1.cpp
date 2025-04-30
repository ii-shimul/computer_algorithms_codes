#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1001];
int visited[1001];
int n, e;
stack<int> ans;

void dfs(int start) {
  visited[start] = 1;
  for (int i = 0; i < graph[start].size(); i++) {
    int node = graph[start][i].first;
    if (visited[node] == 0) {
      dfs(node);
    }
  }
  ans.push(start);
}

int main() {
  cin >> n >> e;
  int u, v, w;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({ v, w });
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      dfs(i);
    }
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << endl;
}
