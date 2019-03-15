#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int size;
    int top;
    int *elements;

    Stack(int siz) //constructor
    {
        size = siz;
        top = -1;
        elements = new int[size];
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
        if(top == size-1)
            return true;
        else
            return false;
    }

    void pushStack(int data)
    {
        if(!(this -> isFullStack()))
        {
            elements[++top] = data;
            cout<<endl<<data<<" pushed to Stack successfully.";
        }
        else
            cout<<"\nStack is full!";
    }

    int popStack()
    {
        int data;
        if(!(this -> isEmptyStack()))
            data = elements[top--];
        else
            cout<<"\nStack is empty!";
        return data;
    }

    void showStack()
    {
        cout<<"The Stack is: ";
        while(!(this -> isEmptyStack()))
            cout<<this -> popStack()<<" ";
    }    
};

int main()
{
    int size,choice,data;
    cout<<"\nEnter the size of the Stack: ";
    cin>>size;
    Stack s(size);
    do
    {
        cout<<"\n1. Push \n2. Pop \n3. Display and Exit";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: {
                cout<<"\nEnter the data value: ";
                cin>>data;
                s.pushStack(data);
                break;
            }    

            case 2:  {
                int value = s.popStack();
                cout<<value<<" was popped from the Stack.";
                break;
            }    

            case 3: {
                s.showStack();
                break;
            }
        }
        cout<<"\nDo you wish to continue? ";
        cin>>choice;
    } while (choice);
    return 0;
}