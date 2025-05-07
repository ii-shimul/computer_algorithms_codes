#include<iostream>
using namespace std;

void Merging(int A[], int B[], int C[], int m, int n)
{
    int i = 0, j = 0, k = 0;

    while(i < m && j < n)
    {
        if( A[i] < B[j])
        {
            C[k] = A[i];
            k++;i++;
        }
        else
        {
            C[k] = B[j];
            k++;j++;
        }
    }

    for( ;i < m; i++)
    {
        C[k] = A[i]; k++;
    }
    for( ; j < n; j++)
    {
        C[k] = B[j]; k++;
    }

}


int main()
{
    int A[] = {1, 3, 7, 8};
    int B[] = {2, 4, 6};

    int m = 4;
    int n = 3;
    int C[m+n];
    Merging(A, B, C, m, n);
    for(int i = 0; i < m+n; i++)
    {
        cout<<C[i]<<" ";
    }
}
