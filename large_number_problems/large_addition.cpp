#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<malloc.h>
#include<string.h>

string sum(string s1, string s2)
{
    int sum, carry = 0, i;
    if(s1.length() > s2.length())
        swap(s1,s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result = "";

    for(i=0; i < s1.length(); i++)
    {
        sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.push_back((sum%10) + '0');
        carry = sum/10;
    }

    for(i = s1.length(); i < s2.length(); i++)
    {
        sum = (s2[i] - '0') + carry;
        result.push_back((sum%10) + '0');
        carry = sum/10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a,b;
    cout<<"Enter first number. ";
    cin>>a;
    cout<<"Enter second number. ";
    cin>>b;
    int choice;
    cout<<"1. Add"<<endl;
    cout<<"Enter your choice. ";
    cin>>choice;
    switch(choice)
    {
        case 1: {
            cout<<"The sum of the entered numbers is "<<sum(a, b)<<" ."<<endl;
            break;
        }
    }
    return 0;
}