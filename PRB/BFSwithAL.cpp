#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
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
        for (int j = 0; j < graph[x].size(); j++) {
            int node = graph[x][j];
            if (visited[node] == 0) {
                visited[node] = 1;
                cout << node << " ";
                q.push(node);
            }
        }
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
    BFS(1);
}
