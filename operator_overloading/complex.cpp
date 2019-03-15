#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<math.h>

class complex_num
{
    public:
    float real, imag;
    
    complex_num() //default constructor
    {}

    complex_num(float r, float i) //constructor with arguments
    {
        real = r;
        imag = i;
    }
    
    ~complex_num() //destructor
    {}

    //overloading + operator
    complex_num operator+(complex_num &b) //+ operator overloaded for type c1 + c2
    {
        complex_num sum(real + b.real, imag + b.imag);
        return sum;
    }

    complex_num operator+(float b) //+ operator overloaded for type c + (real num) 
    {
        complex_num sum(real + b, imag);
        return sum;
    }

    friend complex_num operator+(float a, complex_num &b) //+ operator overloaded for type (imag num) + c
    {
        complex_num result(b.real, a + b.imag);
        return result;
    }

    //overloading - operator
    complex_num operator-(complex_num &b) //- opereator overloaded for type c1 - c2
    {
        complex_num result(real - b.real, imag - b.imag);
        return result;
    }

    complex_num operator-(float x) //- opereator overloaded for type c1 - (real num)
    {
        complex_num result(real - x, imag);
        return result;
    }

    friend complex_num operator-(float a, complex_num &b) //+ operator overloaded for type (imag num) - c
    {
        complex_num result(-b.real, a - b.imag);
        return result;
    }

    //overloading * operator
    complex_num operator*(complex_num &b) //- opereator overloaded for type c1 * c2
    {
        complex_num result((real * b.real) - (imag * b.imag), ((real * b.imag) + (imag * b.real)));
        return result;
    }

    complex_num operator*(float x) //- opereator overloaded for type c1 * (real num)
    {
        complex_num result(real * x, imag * x);
        return result;
    }

    friend complex_num operator*(float a, complex_num &b) //+ operator overloaded for type (imag num) * c
    {
        complex_num result(-a * b.imag, a * b.real);
        return result;
    }

    //overloading ~ operator to find modulus
    float operator~()
    {
        return sqrt(pow(real, 2) + pow(imag, 2));
    }
};

int main()
{
    float re, imag, operand;
    complex_num result;
    int choice;

    cout<<"Enter real part of first complex number: ";
    cin>>re;
    cout<<"Enter imaginary part of first complex number: ";
    cin>>imag;
    complex_num c1(re,imag);

    cout<<"\nEnter real part of second complex number: ";
    cin>>re;
    cout<<"Enter imaginary part of second complex number: ";
    cin>>imag;
    complex_num c2(re,imag);
    
    cout<<"\nThe first complex number is: "<<c1.real<<" + "<<c1.imag<<"i";
    cout<<"\nThe second complex number is: "<<c2.real<<" + "<<c2.imag<<"i";

    cout<<"\n\n1. Add \n2. Subtract \n3. Multiply \n4. Modulus\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1: {
            cout<<"\nAdding in the type c1 + c2: ";
            result = c1 + c2;
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = c1 + operand;
            cout<<"Adding in the type c1 + (real num): ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = operand + c2;
            cout<<"\nAdding in the type (imag num) + c2: ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            break;
        }

        case 2: {
            result = c1 - c2;
            cout<<"Subtracting in the type c1 - c2: ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = c1 - operand;
            cout<<"Subtracting in the type c1 - (real num): ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = operand - c2;
            cout<<"Subtracting in the type (imag num) - c2: ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            break;
        }

        case 3: {
            result = c1 * c2;
            cout<<"Multiplying in the type c1 * c2: ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = c1 * operand;
            cout<<"Multiplying in the type c1 * (real num): ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            cout<<"\nInput your argument: ";
            cin>>operand;
            result = operand * c2;
            cout<<"Multiplying in the type (imag num) * c2: ";
            cout<<result.real<<" + "<<result.imag<<"i"<<endl;

            break;
        }

        case 4: {
            float mod = ~c1;
            cout<<"The modulus of the complex number c1 is: "<<mod<<".\n";
            break;
        }
    }

    return 0;
}