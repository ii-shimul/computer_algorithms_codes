#include<bits/stdc++.h>
using namespace std;

double O_1knapsack(int W, int pro[], int weight[], int n)
{
    int mat[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            if(i==0||j==0)
        {
            mat[i][j] = 0;
        }
        else if(j>=weight[i-1]){
            mat[i][j] = max(mat[i-1][j], pro[i-1]+mat[i-1][j-weight[i-1]]);
        }
        else{
            mat[i][j]=mat[i-1][j];
        }
    }

    int i=n, j=W;
    cout<<"Taken Items: "<<endl;
    while(i>0&&j>0){
        if(mat[i][j]==mat[i-1][j]){
            i--;
        }
        else{
            cout<<i<<" ";
            j=j-weight[i-1];
            i--;
        }

    }


    return mat[n][W];
}






int main()
{
    int n = 4;
    int W = 8;
    int pro[] = {1, 2, 5, 6};
    int weight[] = {2, 3, 4, 5};

    double ans = O_1knapsack(W, pro, weight, n);
    cout<<ans<<endl;



    return 0;
}
