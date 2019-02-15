#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"Enter the side of matrix: ";
    cin>>n;
    int **input = new int* [n];
    int **upper = new int* [n];
    int **lower = new int* [n];
    for(i = 0; i < n; i++)
    {
        *(input + i) = new int [n];
        *(upper + i) = new int [n];
        *(lower + i) = new int [n];
    }
    for(i = 0; i < n; i++)
        for(j = 0;j < n; j++)
        {
            cout<<"Enter value: ";
            cin>>*(*(input + i) + j);
        }

    for(i = 0; i < n; i++)
        for(j = i; j < n; j++)
        {
            if(j >= i)
                *(*(upper + i) + j) = *(*(input + i) + j);
            else
                *(*(upper + i) + j) = 0;
        }    

    for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++)
        {
            if(i >= j)
                *(*(lower + i) + j) = *(*(input + i) + j);
            else
                *(*(lower + i) + j) = 0;
        }
    
    cout<<endl<<"The current matrix is: "<<endl<<endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0;j < n; j++)
            cout<<*(*(input + i) + j)<<" ";
        cout<<endl;
    }

    cout<<endl<<"The upper traiangular matrix is: "<<endl<<endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
             cout<<*(*(upper + i) + j)<<" ";
        cout<<endl;
    }

    cout<<endl<<"The lower traiangular matrix is: "<<endl<<endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
             cout<<*(*(lower + i) + j)<<" ";
        cout<<endl;
    }
    return 0;
} 