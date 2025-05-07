#include<bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visit[1001];
int n, e;
stack<int>ans;

void dfs(int start)
{
    visit[start] = 1;
    for(int j = 1; j <= n; j++)
    {
        if(visit[j] == 0 && graph[start][j] != 0)
        {
            visit[j] = 1;
            dfs(j);
        }
    }
    ans.push(start);
}

int main()
{
    cin>>n>>e;
    int u, v;
    for(int i = 1; i <= e; i++)
    {
        cin>>u>>v;
        graph[u][v] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            dfs(i);
        }
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;



}
