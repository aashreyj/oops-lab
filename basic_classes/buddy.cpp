#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class node
{ 
    public:
    int *data;
    node *link;

    node() //default constructor
    {
        data = NULL;
        link = NULL;
    }

    node(int *x, node* next) //constructor with data input
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

    void list_add(int**);
    void list_del(void);
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

void linked_list::list_add(int **data)
{
    head = new node(*data, head);
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
    cout<<"The base addresses of corresponding memory size index are: ";
    while(temp != NULL)
    {
        cout<<temp -> data<<" -> ";
        temp = temp -> link;
    }
    cout<<endl;
}

class hash_table //let hash function be ceil(log2(x))
{
    public:
    linked_list *list;
    hash_table() //constructor
    {
        int i;
        list = new linked_list [11];
        for(i = 0; i < 11; i++)
            list[i].head = NULL;
    }

    void addHash(int**, int);
    void displayHash(void);
    
    ~hash_table() //destructor
    {}    
};

void hash_table::addHash(int **data, int request)
{
    int key = ceil(log2(request));
    list[key].list_add(data);
}

void hash_table::displayHash()
{
    int i;
    cout<<"The Buddy List is: \n";
    for(i = 0; i < 11; i++)
    {
        cout<<"Memory size: "<<pow(2,i)<<endl;
        list[i].display();
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    hash_table a;
    int i, size, data;
    int *request;
    cout<<"Enter the number of requests: ";
    cin>>size;
    for(i = 0; i < size; i++)
    {
        cout<<"Enter requested size: ";
        cin>>data;
        request = new int [data];
        a.addHash(&request, data);
    }
    cout<<endl;
    a.displayHash();
    return 0;
}