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

bool isSmaller(string str1, string str2) //to check which string is smaller for calculating diffrence
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 
  
string subtract(string str1, string str2) 
{ 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
    string str = ""; //result string 
  
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    for (int i=0; i<n2; i++) 
    { 
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        //Taking borrow if difference is negative
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string to obtain result
    reverse(str.begin(), str.end()); 
  
    return str; 
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

string divide(string number, string divisor) 
{  
    string result=""; 
    int div = 0, expo = 0, i;
    reverse(divisor.begin(), divisor.end());
    for(i = 0; i < divisor.length(); i++)
    {
        div += (divisor[i] - '0') * pow(10, i);
    }
    reverse(divisor.begin(), divisor.end());
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < div) 
       temp = temp * 10 + (number[++idx] - '0'); 
      
    // Repeatedly divide divisor with temp. After  
    // every division, update temp to include one  
    // more digit. 
    while (number.size() > idx) 
    {  
        result += (temp / div) + '0'; 
          
        // Take next digit of number 
        temp = (temp % div) * 10 + number[++idx] - '0'; 
    } 
      
    // If divisor is greater than number 
    if (result.length() == 0) 
        return "0"; 
       
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
    cout<<"1. Add"<<endl<<"2. Subtract"<<endl<<"3. Multiply"<<"4. Divide"<<endl;
    cout<<"Enter your choice. ";
    cin>>choice;
    switch(choice)
    {
        case 1: {
            cout<<"The sum of the entered numbers is "<<sum(a, b)<<" ."<<endl;
            break;
        }

        case 2: {
            cout<<"The difference of the entered numbers is "<<subtract(a, b)<<" ."<<endl;
            break;
        }

        case 3: {
            cout<<"The product of the entered numbers is "<<multiply(a, b)<<" ."<<endl;
            break;
        }

        case 4: {
            cout<<"The quotient of the entered numbers is "<<divide(a, b)<<" ."<<endl;
            break;
        }
    }
    return 0;
}