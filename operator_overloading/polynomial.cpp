#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class term
{
    public:
    float coeff;

    term() //constructor
    {
        coeff = 0;
    }

    term(float coef) //constructor with arguments
    {
        coeff = coef;
    }

    ~term() //destructor
    {}
};

class polynomial
{
    public:
    term *poly;
    int deg;

    polynomial(int degree) //constructor
    {
        deg = degree;
        poly = new term [degree + 1];
        int i;
        for(i = 0; i <= deg; i++)
            poly[i] = 0;
    }

    polynomial(const polynomial &a) //copy constructor
    {
        deg = a.deg;
        poly = new term [deg + 1];
        int i = 0;
        for(i; i <= deg; i++)
            poly[i].coeff = a.poly[i].coeff;
    }

    ~polynomial() //destructor
    {
        delete[] poly;
    }

    void input(void);
    void display(void);
    polynomial operator+(polynomial&);
    polynomial operator-(void);
    polynomial operator*(polynomial&);
    float operator~(void);
};

void polynomial::input()
{
    int i;
    for(i = deg; i >= 0; i--)
    {
        cout<<"Enter the co-efficient of power "<<i<<": ";
        cin>>poly[i].coeff;
    }
}

void polynomial::display()
{
    int i;
    for(i = deg; i >= 0; i--)
        cout<<poly[i].coeff<<"x^"<<i<<" + ";
    cout<<endl;
}

polynomial polynomial::operator+(polynomial &b)
{
    polynomial res(max(deg, b.deg));
    polynomial maxi(res.deg), mini(min(deg, b.deg));
    if(deg > b.deg)
    {
        maxi = *this;
        mini = b;
    }
    else
    {
        maxi = b;
        mini = *this;
    }

    int i;
    for(i = 0; i <= mini.deg; i++)
        res.poly[i].coeff = poly[i].coeff + b.poly[i].coeff;
    for(i; i<= maxi.deg; i++)
        res.poly[i].coeff = maxi.poly[i].coeff;
    return res;
}

polynomial polynomial::operator-()
{
    int i;
    polynomial res(deg);
    for(i = 0; i <= deg; i++)
        res.poly[i].coeff = -poly[i].coeff;
    return res;
}

polynomial polynomial::operator*(polynomial &b)
{
    polynomial res(deg + b.deg);
    int i, j;
    for(i = 0; i <= deg; i++)
        for(j = 0; j <= b.deg; j++)
            res.poly[i + j].coeff += poly[i].coeff * b.poly[j].coeff;
    return res;
}

float polynomial::operator~()
{
    float result = 0, input;
    cout<<"Enter the value for which you want to evaluate the polynomial: ";
    cin>>input;
    int i;
    for(i = 0; i <= deg; i++)
        result += (poly[i].coeff * pow(input, i));
    return result;
}

int main()
{
    int deg, choice;
    cout<<"Enter the degree of the polynomial: ";
    cin>>deg;
    cout<<endl;

    polynomial a(deg);
    a.input();
    cout<<"\n\nThe current polynomial is: ";
    a.display();

    cout<<"\n1. Add \n2. Subtract \n3. Multiply \n4. Evaluate \n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:{
            cout<<"\nEnter the degree of the second polynomial: ";
            cin>>deg;
            polynomial b(deg);
            b.input();

            polynomial result(a + b);
            cout<<"\nThe sum polynomial is: ";
            result.display();
            break;
        }
            
        case 2:{
            cout<<"Enter the degree of the second polynomial: ";
            cin>>deg;
            polynomial b(deg);
            b.input();

            polynomial result(-b);
            result = result + a;
            cout<<"\nThe difference polynomial is: ";
            result.display();
            break;
        }

        case 3:{
            cout<<"Enter the degree of the second polynomial: ";
            cin>>deg;
            polynomial b(deg);
            b.input();

            polynomial result(a * b);
            cout<<"\nThe product polynomial is: ";
            result.display();
            break;
        }

        case 4:{
            float val = ~a;
            cout<<"The value of the polynomial for the given input is: "<<val<<endl;
            break;
        }
    }
    return 0;
}