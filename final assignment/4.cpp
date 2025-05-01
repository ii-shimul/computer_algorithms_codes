#include<bits/stdc++.h>
using namespace std;

void inputMatrix(int n, int e, int graph[101][101]) {
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = graph[v][u] = 1;
  }
}

void inputList(int n, int e, vector<int> graphList[]) {
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    graphList[u].push_back(v);
    graphList[v].push_back(u);
  }
}

int main() {
  int n, e;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> e;

  int graph[101][101] = { 0 };          
  vector<int> graphList[10];

  cout << "Choose input type (1 for Matrix, 2 for List): ";
  int choice;
  cin >> choice;

  if (choice == 1) {
    inputMatrix(n, e, graph);
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        cout << graph[i][j] << " ";
      cout << endl;
    }
  }
  else if (choice == 2) {
    inputList(n, e, graphList);
    cout << "Adjacency List:\n";
    for (int i = 1; i <= n; i++) {
      cout << i << "-> ";
      for (int v : graphList[i])
        cout << v << " ";
      cout << endl;
    }
  }
  else {
    cout << "Invalid choice\n";
  }

  return 0;
}