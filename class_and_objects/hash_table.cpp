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
    cout<<"Node deleted."<<endl;
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
    cout<<endl;
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

class hash_table //let hash function be x%25
{
    public:
    linked_list *list;
    hash_table()
    {
        int i;
        list = new linked_list [25];
        for(i = 0; i < 25; i++)
            list[i].head = NULL;
    }

    void addHash(int);
    void delHash(int);
    int searchHash(int);
    void displayHash(void);
    
    ~hash_table()
    {}    
};

void hash_table::addHash(int data)
{
    int key = data % 25;
    list[key].list_add(data);
}

void hash_table::displayHash()
{
    int i;
    cout<<"The Hash Table is: \n";
    for(i = 0; i < 25; i++)
        list[i].display();
    cout<<endl;
}

int main()
{
    hash_table a;
    int i, size, data;
    cout<<"Enter the number of data elements: ";
    cin>>size;
    for(i = 0; i < size; i++)
    {
        cout<<"Enter data: ";
        cin>>data;
        a.addHash(data);
    }
    cout<<endl;
    a.displayHash();
    return 0;
}