#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin>>n>>e;
    long long int graph[n+1][n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)graph[i][j] = 0;
            else graph[i][j] = INT_MAX;
        }
    }
    int u, v, w;
    for(int i = 1; i <= e; i++)
    {
        cin>>u>>v>>w;
        graph[u][v] = w;
    }
    cout<<"A0"<<endl;
    for(int p = 1; p <= n; p++)
    {
        for(int q = 1; q <= n; q++)
        {
            cout<<graph[p][q]<<" ";
        }
        cout<<endl;
    }


    for(int k = 1; k <= n; k++)
    {
        cout<<"A"<<k<<endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
        for(int p = 1; p <= n; p++)
        {
            for(int q = 1; q <= n; q++)
            {
                cout<<graph[p][q]<<" ";
            }
            cout<<endl;
        }

    }







}
