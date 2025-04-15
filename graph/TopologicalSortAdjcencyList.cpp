#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int visited[1001];
int n, e;
stack<int>ans;

void dfs(int start) {
  visited[start] = 1;
  for (int j = 0; j < graph[start].size(); j++) {
    int node = graph[start][j];
    if (visited[node] == 0) {
      dfs(node);
    }
  }
  ans.push(start);
}

int main() {
  cin >> n >> e;
  int u, v;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
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