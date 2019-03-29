#include<bits/stdc++.h>
using namespace std;

template <class T>
class matrix
{
    public:
    T **mat;

    matrix<T>() //constructor
    {
        int i, j;
        mat = new T* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new T [3];
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                mat[i][j] = 0;
    }

    matrix(const matrix<T> &a) //copy constructor
    {
        int i, j;
        mat = new T* [3];
        for(i = 0; i < 3; i++)
            mat[i] = new T [3];
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

    void input()
    {
        int i, j;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
            {
                cout<<"Enter value: ";
                cin>>mat[i][j];
            }
    }

    void display()
    {
        int i,j;
        for(i = 0; i < 3; i++)
        {
            for(j = 0;j < 3; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }

    matrix<T> operator+(matrix<T> &b)
    {
        matrix<T> result;
        int i, j;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                result.mat[i][j] = mat[i][j] + b.mat[i][j];
        return result;
    }

    matrix<T> operator-(matrix<T> &b)
    {
        matrix<T> result;
        int i, j;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                result.mat[i][j] = mat[i][j] - b.mat[i][j];
        return result;
    }

    matrix<T> operator-()
    {
        matrix<T> result;
        int i, j;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                result.mat[i][j] = -mat[i][j];
        return result;
    }

    matrix<T> operator!()
    {
        matrix<T> result;
        int i, j;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                result.mat[i][j] = mat[j][i];
        return result;
    }

    float operator~()
    {
        return (mat[0][0] * (mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])) - (mat[0][1] * (mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])) + (mat[0][2] * (mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0])); 
    }
    
};

int main()
{
    int choice, choiceType;
    matrix<int> a;
    matrix<float> c;

    cout<<"1. Integer \n2. Float";
    cout<<"\nEnter your choice: \n";
    cin>>choiceType;

    switch(choiceType)
    {
        case 1: {
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
                        matrix<int> b;
                        cout<<"\nInput for second matrix:\n";
                        b.input();

                        cout<<"\nSecond matrix is: \n";
                        b.display();

                        matrix<int> result(a + b);
                        cout<<"\nThe sum matrix is: \n";
                        result.display();
                        break;
                    }

                case 2:{
                        matrix<int> b;
                        cout<<"\nInput for second matrix:\n";
                        b.input();

                        cout<<"\nSecond matrix is: \n";
                        b.display();

                        matrix<int> result(a - b);
                        cout<<"\nThe difference matrix is: \n";
                        result.display();
                        break;
                }

                case 3:{
                    matrix<int> result(!a);
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
                    matrix<int> result(-a);
                    cout<<"Negation of the matrix is :\n";
                    result.display();
                    break;
                }
            }
            cout<<"\nDo you want to continue? ";
            cin>>choice;
            }while(choice);
            break;
        }

        case 2: {
            cout<<"Input for first matrix:\n";
            c.input();
            
            cout<<"\nFirst matrix is: \n";
            c.display();

            do
            {
                cout<<"\n1. Add \n2. Subtract \n3. Transpose \n4. Determinant \n5. Negation\n";
                cout<<"\nEnter your choice: ";
                cin>>choice;

                switch (choice)
                {
                    case 1:{
                        matrix<float> d;
                        cout<<"\nInput for second matrix:\n";
                        d.input();

                        cout<<"\nSecond matrix is: \n";
                        d.display();

                        matrix<float> result(c + d);
                        cout<<"\nThe sum matrix is: \n";
                        result.display();
                        break;
                    }

                case 2:{
                        matrix<float> d;
                        cout<<"\nInput for second matrix:\n";
                        d.input();

                        cout<<"\nSecond matrix is: \n";
                        d.display();

                        matrix<float> result(c - d);
                        cout<<"\nThe difference matrix is: \n";
                        result.display();
                        break;
                }

                case 3:{
                    matrix<float> result(!c);
                    cout<<"\nThe transpose matrix is: \n";
                    result.display();
                    break;
                }

                case 4: {
                    int det = ~c;
                    cout<<"Determinant of the matrix is :"<<det;
                    break;
                }

                case 5: {
                    matrix<float> result(-c);
                    cout<<"Negation of the matrix is :\n";
                    result.display();
                    break;
                }
            }
            cout<<"\nDo you want to continue? ";
            cin>>choice;
            }while(choice);
            break;
        }
        break;
    }
}