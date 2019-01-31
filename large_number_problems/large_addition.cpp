#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<malloc.h>
#include<string.h>

string sum(string s1, string s2)
{
    int sum, carry = 0, i;
    if(s1.length() > s2.length())
        swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result = "";

    for(i=0; i < s1.length(); i++) //scanning through first number
    {
        sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.push_back((sum%10) + '0');
        carry = sum/10;
    }

    for(i = s1.length(); i < s2.length(); i++) //adding remaining digits of second number
    {
        sum = (s2[i] - '0') + carry;
        result.push_back((sum%10) + '0');
        carry = sum/10;
    }
    reverse(result.begin(), result.end()); //final reversing of result string
    return result;
}

string multiply(string num1, string num2) 
{ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    vector<int> result(n1 + n2, 0); 
    
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    // Go from right to left in num1 
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        i_n2 = 0;  
           
        // Scanning num2              
        for (int j=n2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;  
            carry = sum/10; 
   
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
   
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        i_n1++; 
    } 
   
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    if (i == -1) 
    return "0"; 
   
    // generate the result string 
    string res = ""; 
       
    while (i >= 0) 
        res += std::to_string(result[i--]); 
   
    return res; 
}

int main()
{
    string a,b;
    cout<<"Enter first number. ";
    cin>>a;
    cout<<"Enter second number. ";
    cin>>b;
    int choice;
    cout<<"1. Add"<<endl<<"2. Subtract"<<endl<<"3. Multiply"<<"4. Divide"<<endl;
    cout<<"Enter your choice. ";
    cin>>choice;
    switch(choice)
    {
        case 1: {
            cout<<"The sum of the entered numbers is "<<sum(a, b)<<" ."<<endl;
            break;
        }

        case 3: {
            cout<<"The product of the entered numbers is "<<multiply(a, b)<<" ."<<endl;
        }
    }
    return 0;
}