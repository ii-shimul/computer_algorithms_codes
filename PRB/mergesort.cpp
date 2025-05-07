#include<iostream>
using namespace std;

void Merging(int L, int mid, int H, int ara[])
{
    int m = mid-L+1;
    int n = H - mid;
    int A[m];
    int B[n];

    for(int i = 0; i < m; i++)
    {
        A[i] = ara[L+i];
    }
    for(int j = 0; j < n; j++)
    {
        B[j] = ara[mid+1+j];
    }

    int i = 0, j = 0, k = L;
    while(i < m && j < n)
    {
        if(A[i] < B[j])
        {
            ara[k] = A[i];
            i++;
            k++;
        }
        else
        {
            ara[k] = B[j];
            j++;
            k++;
        }
    }

    for( ;i < m; i++)
    {
        ara[k] = A[i];
        k++;
    }
    for( ;j < n; j++)
    {
        ara[k] = B[j];
        k++;
    }
}


void MergeSort(int L, int H, int ara[])
{
    if(L >= H) return;

    int mid = L+(H-L)/2;
    MergeSort(L, mid, ara);
    MergeSort(mid+1, H, ara);
    Merging(L, mid, H, ara);
}


int main()
{
    int n;
    cin>>n;
    int ara[n];
    for(int i = 0; i < n; i++)
    {
        cin>>ara[i];
    }

    MergeSort(0, n-1, ara);

    for(int i = 0; i < n; i++)
    {
        cout<<ara[i]<<" ";
    }
}
