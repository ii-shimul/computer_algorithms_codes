#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, E;
    cin>>n>>E;

    int adj[n+1][n+1];
    memset(adj, 0, sizeof(adj));
    int u, v, w;
    for(int i = 1; i <= E; i++)
    {
        cin>>u>>v>>w;
        adj[u][v] = w;
        //adj[v][u] = w;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }





}
