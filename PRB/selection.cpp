#include<iostream>
using namespace std;


void selection_sort(int num[], int n)
{
    for(int i = 0; i < n; i++) // Position Picking loop
    {
        for(int j = i+1; j < n; j++) // Pointer iteration loop
        {
            if(num[i] > num[j])
            {
                swap(num[i], num[j]);
            }
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
    }

    selection_sort(num, n);

    for(int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }



}
