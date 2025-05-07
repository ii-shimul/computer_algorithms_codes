#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int visit[1001];
int n, e;

void DFS(int start)
{
   visit[start] = 1;
   cout<<start<<" ";

   for(int j = 0; j < graph[start].size(); j++)
   {
       int node = graph[start][j];
       if(visit[node] == 0)
       {
           visit[node] = 1;
           DFS(node);
       }
   }
}

int main()
{
    cin>>n>>e;
    int u, v;
    for(int i = 1; i <= e; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1);
}

