#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, e;
    cin>>n>>e;
    int graph[n+1][n+1];
    memset(graph, 0, sizeof(graph));
    int u, v, w;
    for(int i = 1; i <= e; i++)
    {
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
