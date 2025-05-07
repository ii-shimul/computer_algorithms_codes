#include<iostream>
using namespace std;

void insertion_sort(int num[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int x = num[i]; //Picked line
        int j = i-1; // Predecessor checker pointer

        while( j >= 0 && num[j] > x)
        {
            num[j+1] = num[j]; // Swapping loop
            j--;
        }
        num[j+1] = x; //Fixed line
    }
}



int main()
{
     int n; // size declaration
     cin>>n; //Size Input
     int num[n]; // n size array declare
     for(int i = 0; i < n; i++)
     {
         cin>>num[i]; // Array input using for loop
     }

     insertion_sort(num, n);

     for(int i = 0; i < n; i++)
     {
         cout<<num[i]<<" ";
     }



}
