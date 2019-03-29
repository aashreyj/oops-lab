#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{ 
    public:
    T data;
    node<T> *link;

    node() //default constructor
    {}
    
    node(T x, node<T>* next) //constructor with data input
    {
        data = x;
        link = next;
    }

    ~node() //destructor
    {}
};

template <class T>
class Queue
{
    public:
    node<T> *head;
    
    Queue() //linked list constructor
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
        T val;
        node<T>* temp = head;
        node<T>* del;
        while(temp -> link -> link != NULL)
            temp = temp -> link;
        val = temp -> link -> data;
        del = temp -> link -> link;
        temp -> link = NULL;
        delete del;
        cout<<"Node dequeued. Value was "<<val<<endl<<endl;
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

    ~Queue() //linked list destructor
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
    int index, choiceType, size, choice, cont;
    Queue<int> a;
    Queue<char> b;

    cout<<"1. Integer \n2. Character";
    cout<<"\nEnter your choice: ";
    cin>>choiceType;

    switch(choiceType)
    {
        case 1: {
            int data;
            do 
            {
                cout<<"1. Create new Queue. \n2. Enqueue \n3. Dequeue. \n4. Search \n5. Display Queue\n\n";
                cout<<"Enter choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1: {
                        cout<<"Enter the size of the queue: ";
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
                        cout<<"Enter the data: ";
                        cin>>data;
                        a.list_add(data);
                        cout<<"Added.\n";
                        break;
                    }

                    case 3: {
                        a.list_del();
                        a.display();
                        break;
                    }

                    case 4: {
                        int key, index;  
                        cout<<"Enter element to be searched: ";
                        cin>>key;
                        index = a.search(key);
                        if(index == -1)
                            cout<<"Node not found."<<endl<<endl;
                        else
                            cout<<"Node found in the queue at index "<<index<<"."<<endl<<endl;
                        break;
                    }

                    case 5: {
                        a.display();
                        break;
                    }
                }
                cout<<"Do you want to continue (1/0)? ";
                cin>>cont;
                cout<<endl<<endl;
            } while(cont);
            break;
        }

        case 2: {
            char data;    
            do 
            {
                cout<<"1. Create new Queue. \n2. Enqueue \n3. Dequeue. \n4. Search \n5. Display Queue\n\n";
                cout<<"Enter choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1: {
                        cout<<"Enter the size of the queue: ";
                        cin>>size;
                        for(index = 0; index < size; index++)
                        {
                            cout<<"Enter the data: ";
                            cin>>data;
                            b.list_add(data);
                        }
                        cout<<"List Created."<<endl<<endl;
                        break;
                    }

                    case 2: {
                        cout<<"Enter the data: ";
                        cin>>data;
                        b.list_add(data);
                        cout<<"Added.\n";
                        break;
                    }

                    case 3: {
                        b.list_del();
                        b.display();
                        break;
                    }

                    case 4: {
                        int index;
                        char key;  
                        cout<<"Enter element to be searched: ";
                        cin>>key;
                        index = b.search(key);
                        if(index == -1)
                            cout<<"Node not found."<<endl<<endl;
                        else
                            cout<<"Node found in the queue at index "<<index<<"."<<endl<<endl;
                        break;
                    }

                    case 5: {
                        b.display();
                        break;
                    }
                }
                cout<<"Do you want to continue (1/0)? ";
                cin>>cont;
                cout<<endl<<endl;
            } while(cont);
            break;
        }
    }

    cout<<"Queue will be deleted..."<<endl;
    return 0;
}