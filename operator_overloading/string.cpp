#include<bits/stdc++.h>
using namespace std;
#include<math.h>
#include<string.h>

class MyString
{
    public:
    string text;

    MyString operator+(MyString&);  //for concatenation
    int operator*(MyString&);  //for comparison
    bool operator-(MyString&);  //for substring checking
    void display(void);  //for display
};

MyString MyString::operator+(MyString &b)
{
    MyString res;
    res.text = text.append(b.text);
    return res;
}

int MyString::operator*(MyString &b)
{
    int index = 0, diff = 0;
    for(index; index < min(text.length(), b.text.length()); index++)
        if(text[index] != b.text[index])
        {
            diff = text[index] - b.text[index];
            break;
        }
    return diff;
}

bool MyString::operator-(MyString &b)
{
    if(text.find(b.text) == string::npos)
        return false;
    else
        return true;
}

void MyString::display()
{
    cout<<text;
}

int main()
{
    MyString a, b;
    int choiceMain, choiceOption;
    cout<<"Enter the first string: ";
    cin>>a.text;

    cout<<"Enter the second string: ";
    cin>>b.text;
    
    do
    {
        cout<<"\n1. Concatenate \n2. Check Substring \n3. Compare";
        cout<<"\nEnter your choice: ";
        cin>>choiceOption;

        switch(choiceOption)
        {
            case 1: {
                cout<<"\nThe concatenated string is: ";
                (a + b).display();
                break;
            }

            case 2: {
                if(a - b)
                    cout<<endl<<b.text<<" is a sub-string of "<<a.text;
                else
                    cout<<endl<<b.text<<" is not a sub-string of "<<a.text;
                break;
            }

            case 3: {
                if(a * b == 0)
                    cout<<"\nThe entered strings are equal!";
                else if(a * b < 0)
                    cout<<"\n"<<b.text<<" is larger than "<<a.text;
                else
                    cout<<"\n"<<b.text<<" is smaller than "<<a.text;
            }
        }

        cout<<"\nDo you want to continue? ";
        cin>>choiceMain;
    } while (choiceMain);
    cout<<endl;
    return 0;
}