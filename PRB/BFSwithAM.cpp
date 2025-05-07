#include<bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visited[1001];
int n, e;


void BFS(int start) {
    //Initial Step
    visited[start] = 1;
    cout << start << " ";
    queue<int>q;
    q.push(start);

    //Repeating Step
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0 && graph[x][j] != 0) {
                visited[j] = 1;
                cout << j << " ";
                q.push(j);
            }
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
    BFS(1);
}
