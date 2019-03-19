#include<bits/stdc++.h>
using namespace std;
class matrix
{
    public:
    int **mat;

    matrix() //constructor
    {
        int i, j;
        mat = new int* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new int [3];
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                mat[i][j] = 0;
    }

    matrix(const matrix &a) //copy constructor
    {
        int i, j;
        mat = new int* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new int [3];
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                mat[i][j] = a.mat[i][j];
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
    int operator~(void); //determinant
};

void matrix::input()
{
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            cout<<"Enter value: ";
            cin>>mat[i][j];
        }
}

void matrix::display()
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0;j < 3; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

matrix matrix::operator+(matrix &b)
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            result.mat[i][j] = mat[i][j] + b.mat[i][j];
    return result;
}

matrix matrix::operator-(matrix &b)
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            result.mat[i][j] = mat[i][j] - b.mat[i][j];
    return result;
}

matrix matrix::operator-()
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            result.mat[i][j] = -mat[i][j];
    return result;
}

matrix matrix::operator!()
{
    matrix result;
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            result.mat[i][j] = mat[j][i];
    return result;
}

int matrix::operator~()
{
    return (mat[0][0] * (mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])) - (mat[0][1] * (mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])) + (mat[0][2] * (mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0])); 
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
        cout<<"\n1. Add \n2. Subtract \n3. Transpose \n4. Determinant \n5. Negation\n";
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
                int det = ~a;
                cout<<"Determinant of the matrix is :"<<det;
                break;
            }

            case 5: {
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