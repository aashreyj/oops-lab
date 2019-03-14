#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{ 
    public:
    int data;
    node *left, *right;

    node() //defualt constructor
    {
        right = left = NULL;
    }

    ~node() //destructor
    {}
};

class bst
{
    public:
    node *root;

    bst() //default constructor
    {
        root = NULL;
    }

    ~bst() //destructor
    {}

    void insert(node*, node*);
    void inorder(node*);
    node* search(node*, int);
};

void bst::insert(node* current, node* toBeAdded) //current is root of current tree (subtree)
{
    if(root == NULL) //bst is initially empty
    {
        root = new node;
        root -> data = toBeAdded -> data;
        root -> left = root -> right = NULL;
        cout<<"Added.\n";
    }
    else if(toBeAdded -> data < current -> data)
    {
        if(current -> left != NULL)
            insert(current -> left, toBeAdded); //recurring for left subtree
        else
        {
            current -> left = toBeAdded; //adding to left subtree
            (current -> left) -> left = (current -> left) -> right = NULL;
        }
        cout<<"Added.\n";
    }
    else if(toBeAdded -> data > current -> data)
    {
        if(current -> right != NULL) //recurring for right subtree
            insert(current -> right, toBeAdded);
        else
        {
            current -> right = toBeAdded; //adding to right subtree
            (current -> right) -> left = (current -> right) -> right = NULL;
        }
        cout<<"Added.\n";
    }
    else //duplicate value
        cout<<"\nElement already present in tree."<<endl;
}

node* bst::search(node *current, int key)
{
    if(current -> data == key) //base case
        return current;
    else if(current -> data > key) //recursively searching in left subtree
        search(current -> left, key);
    else
        search(current -> right, key); //recursively searching in right subtree
    return NULL;
}

void bst::inorder(node *current)
{
    if(current != NULL) //inorder traversal
    {
        inorder(current -> left);
        cout<<current -> data<<" ";
        inorder(current -> right);
    }
}

int main()
{
    bst a;
    node *temp;
    int i,choice;
    do
    {
        temp = new node;
        cout<<"Enter data: ";
        cin>>temp -> data;
        a.insert(a.root, temp);
        cout<<"Do you want to continue? "; 
        cin>>choice;
        cout<<endl;
    }
    while(choice);
    do
    {
        cout<<"\n1. Insert more elements \n2. Search element \n3. Print inorder traversal";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: {
                temp = new node;
                cout<<"Enter data: ";
                cin>>temp -> data;
                a.insert(a.root, temp);
                break;
            }

            case 2: {
                int key;
                cout<<"\nEnter the search key: ";
                cin>>key;
                if(a.search(a.root, key) != NULL)
                    cout<<"The key was found in the tree.";
                else
                    cout<<"The key was not found.";
                break;
            }
            
            case 3: {
                cout<<"The inorder traversal of the bst gives: ";
                a.inorder(a.root);
                break;
            }
        }
        cout<<"Do you want to continue? "; 
        cin>>choice;
        cout<<endl;
    } while (choice);
    cout<<endl;
}