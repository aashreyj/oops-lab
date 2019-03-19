#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<math.h>

class complex_num
{
    public:
    int real, imag;
    
    complex_num() //default constructor
    {}

    complex_num(int r, int i) //constructor with arguments
    {
        real = r;
        imag = i;
    }

    complex_num(const complex_num &a) //copy constructor
    {
        real = a.real;
        imag = a.imag;
    }
    
    ~complex_num() //destructor
    {}

    //overloading + operator for addition
    complex_num operator+(complex_num &b) //+ operator overloaded for type c1 + c2
    {
        complex_num sum(real + b.real, imag + b.imag);
        return sum;
    }

    //overloading - operator for subtraction
    complex_num operator-(complex_num &b) //- operator overloaded for type c1 - c2
    {
        complex_num result(real - b.real, imag - b.imag);
        return result;
    }

    //overloading - operator to find negation
    complex_num operator-()
    {
        complex_num result(-real, -imag);
        return result;
    }

    //overloading * operator for multiplication
    complex_num operator*(complex_num &b) //- operator overloaded for type c1 * c2
    {
        complex_num result((real * b.real) - (imag * b.imag), ((real * b.imag) + (imag * b.real)));
        return result;
    }
};

class matrix
{
    public:
    complex_num **mat;

    matrix() //constructor
    {
        int i, j;
        mat = new complex_num* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new complex_num [3];
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                mat[i][j].imag = mat[i][j].real = 0;
    }

    matrix(const matrix &a) //copy constructor
    {
        int i, j;
        mat = new complex_num* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new complex_num [3];
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
            {
                mat[i][j].real = a.mat[i][j].real;
                mat[i][j].imag = a.mat[i][j].imag;
            }
    }

    ~matrix() //destructor
    {
        int i;
        for(i = 0; i < 3; i++)
            delete[] mat[i];
        delete[] mat;
    }

    void input(void);
    void display(void);
    matrix operator+(matrix&); //addition
    matrix operator-(matrix&); //subtraction
    matrix operator!(void); //transpose
    matrix operator-(void); //negation
};

void matrix::input()
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout<<"Enter real component: ";
            cin>>mat[i][j].real;

            cout<<"Enter imaginary component: ";
            cin>>mat[i][j].imag;
        }
        cout<<endl;
    }
}

void matrix::display()
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0;j < 3; j++)
            cout<<mat[i][j].real<<" + "<<mat[i][j].imag<<"i";
        cout<<endl;
    }
}

matrix matrix::operator+(matrix &b) //addition
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            result.mat[i][j] = mat[i][j] + b.mat[i][j];
        }
    return result;
}

matrix matrix::operator-(matrix &b) //subtraction
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            result.mat[i][j] = mat[i][j] - b.mat[i][j];
        }
    return result;
}

matrix matrix::operator-() //negation
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            result.mat[i][j] = -mat[i][j];
        }
    return result;
}

matrix matrix::operator!() //transpose
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            result.mat[i][j] = mat[j][i];
        }
    return result;
}

int main()
{
    int choice;
    matrix a;
    cout<<"Input for first matrix:\n";
    a.input();

    cout<<"\nFirst matrix is: \n";
    a.display();

    do
    {
        cout<<"\n1. Add \n2. Subtract \n3. Transpose \n4. Negation\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:{
                matrix b;
                cout<<"\nInput for second matrix:\n";
                b.input();

                cout<<"\nSecond matrix is: \n";
                b.display();

                matrix result(a + b);
                cout<<"\nThe sum matrix is: \n";
                result.display();
                break;
            }

            case 2:{
                matrix b;
                cout<<"\nInput for second matrix:\n";
                b.input();

                cout<<"\nSecond matrix is: \n";
                b.display();

                matrix result(a - b);
                cout<<"\nThe difference matrix is: \n";
                result.display();
                break;
            }

            case 3:{
                matrix result(!a);
                cout<<"\nThe transpose matrix is: \n";
                result.display();
                break;
            }

            case 4: {
                matrix result(-a);
                cout<<"Negation of the matrix is :\n";
                result.display();
                break;
            }
        }
        cout<<"\nDo you want to continue? ";
        cin>>choice;
    }while(choice);
}