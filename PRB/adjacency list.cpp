#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>>graph[n + 1];
    int u, v, w;
    for (int i = 1; i <= e; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << "(" << graph[i][j].first << " " << graph[i][j].second << ")";
        }
        cout << endl;
    }
}
