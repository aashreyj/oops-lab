#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class matrix
{
    public:
    int **mat, rows, columns;

    matrix(int r, int c) //constructor
    {
        int i, j;
        rows = r;
        columns = c;
        mat = new int* [r];
        for(i = 0; i < r; i++)
            mat[i] = new int [c];
        for(i = 0; i < rows; i++)
            for(j = 0;j < columns; j++)
               mat[i][j] = 0;
    }

    ~matrix() //destructor
    {
        int i;
        for(i = 0; i < rows; i++)
            delete[] mat[i];
        delete[] mat;
    }

    void input(void);
    void multiply(matrix&);
    bool isCompatible(matrix&);
    void display(void);
};

void matrix::input()
{
    int i, j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
        {
            cout<<"Enter value: ";
            cin>>mat[i][j];
        }
}

void matrix::display()
{
    int i,j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0;j < columns; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

bool matrix::isCompatible(matrix &b)
{
    if(columns == b.rows)
        return true;
    else
        return false;
}

void matrix::multiply(matrix &b)
{
    matrix result(rows, b.columns);
    int i, j, k, sum;

    cout<<"\n\nMatrix A was: \n";
    this -> display();
    cout<<"\nMatrix B was: \n";
    b.display();

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < b.columns; j++)
        {
            //result.mat[i][j] = 0;
            for(k = 0; k < columns; k++)
            {
                sum = mat[i][k] * (b.mat)[k][j];
                (result.mat)[i][j] += sum;
            }
        }
    }

    cout<<"\n\nThe Product matrix is: \n";
    result.display();
}

int main()
{
    int r,c;
    cout<<"Enter the rows of first matrix: ";
    cin>>r;
    cout<<"Enter the columns of first matrix: ";
    cin>>c;
    matrix a(r,c);
    cout<<"Input for first matrix:\n";
    a.input();

    cout<<"\nEnter the rows of second matrix: ";
    cin>>r;
    cout<<"Enter the columns of second matrix: ";
    cin>>c;
    matrix b(r,c);
    if(!a.isCompatible(b))
        cout<<"\nThe two matrices cannot be multiplied.\n";
    else
    {
        cout<<"Input for second matrix:\n";
        b.input();
        a.multiply(b);
    }
    return 0;
}