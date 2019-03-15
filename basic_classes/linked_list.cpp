#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{ 
    public:
    int data;
    node *link;

    node() //default constructor
    {}
    
    node(int x, node* next) //constructor with data input
    {
        data = x;
        link = next;
    }

    ~node() //destructor
    {}
};

class linked_list
{
    public:
    node *head;
    
    linked_list() //linked list constructor
    {
        head = NULL;
    }

    void list_add(int);
    void list_del(void);
    int search(int);
    void display(void);

    ~linked_list() //linked list destructor
    {
        while(head != NULL)
        {
            node* temp = head;
            head = head -> link;
            delete temp;
        }
    }
};

void linked_list::list_add(int data)
{
    head = new node(data, head);
}

void linked_list::list_del()
{
    if(head == NULL)
    {
        cout<<"Empty list."<<endl;
        return;
    }
    node* temp = head;
    head = head -> link;
    delete temp;
    cout<<"Node deleted."<<endl<<endl;
}

void linked_list::display()
{
    node *temp = head;
    cout<<"The current linked list is: ";
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> link;
    }
    cout<<endl<<endl;
}

int linked_list::search(int key)
{
    int index = 1;
    node *temp = head;
    while(temp != NULL)
    {
        if(temp -> data == key)
            return index;
        temp = temp -> link;
        index++;
    }
    return -1;
}

int main()
{
    int index, data, size, choice, cont;
    linked_list a;
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
                a.list_del();
                a.display();
                break;
            }

            case 3: {
                int key, index;  
                cout<<"Enter element to be searched: ";
                cin>>key;
                index = a.search(key);
                if(index == -1)
                    cout<<"Node not found."<<endl<<endl;
                else
                    cout<<"Node found in the list at index "<<index<<"."<<endl<<endl;
                break;
            }

            case 4: {
                a.display();
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