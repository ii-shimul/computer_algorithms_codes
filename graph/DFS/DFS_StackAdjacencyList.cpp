#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1001];
int visit[1001];
int n, e;

void DFS(int start) {
  // initial step
  visit[start] = 1;
  cout << start << " ";
  stack<int>stk;
  stk.push(start);

  // repeating step
  while (!stk.empty()) {
    int x = stk.top();
    for (int j = 0; j < graph[x].size(); j++) {
      int node = graph[x][j];
      if (visit[node] == 0) {
        visit[node] = 1;
        cout << node << " ";
        stk.push(node);
        x = stk.top();
        j = 0;
      }
    }
    stk.pop();
  }
}

int main() {
  cin >> n >> e;
  int u, v;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  DFS(1);
}