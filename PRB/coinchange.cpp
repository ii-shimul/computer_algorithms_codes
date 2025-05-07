#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int coins[n];
    for(int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    long long int change[n+1][m+1];
    for(int i = 1; i < m+1; i++)
    {
        change[0][i] = INT_MAX;
    }
    for(int i = 0; i < n+1; i++)
    {
        change[i][0] = 0;
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if(coins[i-1] > j)
            {
                change[i][j] = change[i-1][j];
            }
            else
            {
                change[i][j] = min(change[i-1][j], 1 + change[i][j-coins[i-1]]);
            }
        }
    }

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            cout<<change[i][j]<<" ";
        }
        cout<<endl;
    }


    int i = n, j = m;
    while( i > 0)
    {
        while(true)
        {
            if(change[i][j] == change[i-1][j])
            {
                i = i-1;
                break;
            }
            else
            {
                j = j - coins[i-1];
                cout<<coins[i-1]<<" ";
            }
        }
    }





}
