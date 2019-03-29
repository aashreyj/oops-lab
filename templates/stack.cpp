#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
    public:
    int size;
    int top;
    T *elements;

    Stack(int siz) //constructor
    {
        size = siz;
        top = -1;
        elements = new T[size];
    }

    ~Stack() //destructor
    {
        delete[] elements;
    }

    bool isEmptyStack()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFullStack()
    {
        if(top == size - 1)
            return true;
        else
            return false;
    }

    void pushStack(T data)
    {
        if(!(this -> isFullStack()))
        {
            elements[++top] = data;
            cout<<endl<<data<<" pushed to Stack successfully.";
        }
        else
            cout<<"\nStack is full!";
    }

    T popStack()
    {
        T data;
        if(!(this -> isEmptyStack()))
            data = elements[top--];
        else
            cout<<"\nStack is empty!";
        return data;
    }

    void showStack()
    {
        while(!(this -> isEmptyStack()))
            cout<<this -> popStack()<<" ";
    }    
};

int main()
{
    int size,choice,choice1,choicee;
    cout<<"\nEnter the size of the Stack: ";
    cin>>size;
    Stack<int> s1(size);
    Stack<float> s2(size);
    Stack<char> s3(size);
    do
    {
        cout<<"\n1. Push \n2. Pop \n3. Display and Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: {
                cout<<"\n1. Integer Stack \n2. Float Stack \n3. Character Stack";
                cout<<"\nEnter your choice: ";
                cin>>choice1;
                switch (choice1)
                {
                    case 1: {
                        int data;
                        cout<<"\nEnter the data value: ";
                        cin>>data;
                        s1.pushStack(data);
                        break;
                    }

                    case 2: {
                        float data;
                        cout<<"\nEnter the data value: ";
                        cin>>data;
                        s2.pushStack(data);
                        break;
                    }

                    case 3: {
                        char data;
                        cout<<"\nEnter the data value: ";
                        cin>>data;
                        s3.pushStack(data);
                        break;
                    }
                }
                break;
            }    

            case 2:  {
                switch (choice1)
                {
                    case 1: {
                        int value = s1.popStack();
                        cout<<value<<" was popped from the Stack.";
                        break;
                    }

                    case 2: {
                        float value = s2.popStack();
                        cout<<value<<" was popped from the Stack.";
                        break;
                    }

                    case 3: {
                        char value = s3.popStack();
                        cout<<value<<" was popped from the Stack.";
                        break;
                    }
                }
                break;
            }    

            case 3: {
                cout<<"The integer stack is: \n";
                s1.showStack();

                cout<<"The float stack is: \n";
                s2.showStack();

                cout<<"The character stack is: \n";
                s3.showStack();
                break;
            }
        }
        cout<<"\nDo you wish to continue? ";
        cin>>choicee;
    } while (choicee);
    return 0;
}