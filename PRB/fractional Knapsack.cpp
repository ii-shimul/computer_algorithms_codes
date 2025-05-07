#include<bits/stdc++.h>
using namespace std;
struct frac{
    int object;
    int profit;
    int weight;
    double PbW;
};

bool comparePbW(frac &f1, frac &f2)
{
    if(f1.PbW > f2.PbW) return true;
    else return false;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int prof[n];
    frac knap[n];

    for(int i = 0; i < n; i++)
    {
        knap[i].object = i;
        cin>>knap[i].profit;
        prof[i] = knap[i].profit;
    }

    for(int i = 0; i < n; i++)
    {
        cin>>knap[i].weight;
    }

    for(int i =0 ; i < n; i++)
    {
        knap[i].PbW = double(knap[i].profit)/double(knap[i].weight);
    }

    sort(knap, knap+n, comparePbW);

    double X[n];
    memset(X, 0, sizeof(X));

    int rw = m;
    int i = 0;

    while( rw > 0)
    {
        if( rw >= knap[i].weight)
        {
            X[knap[i].object] = 1;
            rw = rw - knap[i].weight;
        }
        else
        {
            X[knap[i].object] = double(rw)/double(knap[i].weight);
            rw = 0;
        }
        i++;
    }

    double maxprofit = 0;
    for(int i = 0; i < n; i++)
    {
        maxprofit = maxprofit+(X[i]*double(prof[i]));
    }
    cout<<maxprofit<<endl;








}
