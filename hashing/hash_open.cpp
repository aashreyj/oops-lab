#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct hashNode
{
    int data;
    bool isFilled;
};

int main() //let hash function be x % 10
{
    hashNode table[10];
    int key, i, input, probe;
    for(i = 0; i < 10; i++)
        table[i].isFilled = false;
    for(i = 0; i < 10; i++)
    {
        cout<<"Enter data input: ";
        cin>>input;
        key = input % 10;
        if(!table[key].isFilled)
        {
            table[key].data = input;
            table[key].isFilled = true;
        }
        else
        {
            probe = key;
            while(table[probe].isFilled && probe < 10)
                probe++; 
            table[probe].data = input;
            table[probe].isFilled = true;
        }
    }

    cout<<"The current hash table is: ";
    for(i = 0; i < 10; i++)
        cout<<table[i].data<<" ";
    cout<<endl;
    return 0;
}