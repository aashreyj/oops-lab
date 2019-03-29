#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{ 
    public:
    T data;
    node *link;

    node() //default constructor
    {}
    
    node(T x, node* next) //constructor with data input
    {
        data = x;
        link = next;
    }

    ~node() //destructor
    {}
};

template <class T>
class linked_list
{
    public:
    node<T> *head;
    
    linked_list() //linked list constructor
    {
        head = NULL;
    }

    void list_add(T data)
    {
        head = new node<T>(data, head);
    }
    
    void list_del()
    {
        if(head == NULL)
        {
            cout<<"Empty list."<<endl;
            return;
        }
        node<T>* temp = head;
        head = head -> link;
        delete temp;
        cout<<"Node deleted."<<endl<<endl;
    }

    void display()
    {
        node<T> *temp = head;
        cout<<"The current linked list is: ";
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> link;
        }
        cout<<endl<<endl;
    }

    int search(T key)
    {
        int index = 1;
        node<T> *temp = head;
        while(temp != NULL)
        {
            if(temp -> data == key)
                return index;
            temp = temp -> link;
            index++;
        }
        return -1;
    }

    ~linked_list() //linked list destructor
    {
        while(head != NULL)
        {
            node<T>* temp = head;
            head = head -> link;
            delete temp;
        }
    }
};

int main()
{
    int index, size, choice, cont, choice1;
    linked_list<int> a;
    linked_list<char> b;

    do 
    {
        cout<<"1. Enter new list. \n2. Delete first node. \n3. Search node \n4. Display node\n\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: {
                cout<<"Enter the size of the linked list: ";
                cin>>size;

                cout<<"\n1. Integer \n2. Character";
                cout<<"\nEnter your choice: \n";
                cin>>choice1;

                switch(choice1)
                {
                    case 1: {
                        int data;
                        for(index = 0; index < size; index++)
                        {
                            cout<<"Enter the data: ";
                            cin>>data;
                            a.list_add(data);
                        }
                        cout<<"List Created."<<endl<<endl;
                        break;
                    }

                    case 2: {
                        char data;
                        for(index = 0; index < size; index++)
                        {
                            cout<<"Enter the data: ";
                            cin>>data;
                            b.list_add(data);
                        }
                        cout<<"List Created."<<endl<<endl;
                        break;
                    }
                }
                break;
            }

            case 2: {
                a.list_del();
                a.display();

                b.list_del();
                b.display();
                break;
            }

            case 3: {
                int index;  

                cout<<"\n1. Integer \n2. Character";
                cout<<"\nEnter your choice: \n";
                cin>>choice1;

                switch(choice1)
                {
                    case 1: {
                        int key;
                        cout<<"Enter element to be searched: ";
                        cin>>key;
                        index = a.search(key);
                        if(index == -1)
                            cout<<"Node not found."<<endl<<endl;
                        else
                            cout<<"Node found in the list at index "<<index<<"."<<endl<<endl;
                        break;
                    }

                    case 2: {
                        char key;
                        cout<<"Enter element to be searched: ";
                        cin>>key;
                        index = b.search(key);
                        if(index == -1)
                            cout<<"Node not found."<<endl<<endl;
                        else
                            cout<<"Node found in the list at index "<<index<<"."<<endl<<endl;
                        break;
                    }
                }
                break;
            }

            case 4: {
                a.display();
                b.display();
                break;
            }
        }
        cout<<"Do you want to continue (1/0)? ";
        cin>>cont;
        cout<<endl<<endl;
    } while(cont);
    cout<<"List will be deleted..."<<endl;
    return 0;
}