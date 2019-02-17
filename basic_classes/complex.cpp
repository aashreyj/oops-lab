#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class complex_number
{
    public:
    float real, imaginary;

    complex_number()
    {}

    ~complex_number()
    {}

    complex_number add(complex_number s2)
    {
        complex_number sum;
        sum.real = real + s2.real;
        sum.imaginary = imaginary + s2.imaginary;
        return sum;
    }

    complex_number subtract(complex_number s2)
    {
        complex_number diff;
        diff.real = real - s2.real;
        diff.imaginary = imaginary - s2.imaginary;
        return diff;
    }
};

int main()
{
    complex_number a,b;
    complex_number result;
    cout<<"Enter real part of first number: ";
    cin>>a.real;
    cout<<"Enter imaginary part of first number: ";
    cin>>a.imaginary;

    cout<<"\nEnter real part of second number: ";
    cin>>b.real;
    cout<<"Enter imaginary part of second number: ";
    cin>>b.imaginary;

    cout<<"\n\n1. Add \n2. Subtract";
    int choice;
    cout<<"\nEnter choice: ";
    cin>>choice;

    switch (choice)
    {
        case 1: {
            result = a.add(b);
            break; 
        }

        case 2: {
            result = a.subtract(b);
            break;
        }
    }

    cout<<"\nThe result of the operation is: ";
    cout<<"\nReal part: "<<result.real;
    cout<<"\nImaginary part: "<<result.imaginary<<endl;
    return 0;
}