#include<bits/stdc++.h>
using namespace std;

class Graph
{ 
    int V;
    list<int> *adj;
    void DFSUtil(int v,bool visited[]); //Depth-first Search Utility Function
    
    public:
    Graph(int V);
    void addEdge(int u,int v);
    void connectedComponents();
};

Graph::Graph(int V) //constructor
{
    V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int u) //add new edge to vertices list
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i]) //if vertex is not visited, do DFS
            DFSUtil(*i, visited);
}

void Graph::connectedComponents() //obtain the connected components
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int v=0; v<V; v++)
    {
        if(visited[v] == false)
        {
            DFSUtil(v, visited);
            cout<<endl;
        }
    }
}

int main()
{
    fstream fin;
    fin.open("sample.txt"); //input file containing vertex info
    while(!fin.eof())
    {
        int vertex, a, b, k;
        fin>>vertex;
        k = vertex;
        Graph g(vertex);
        while(vertex > 0)
        {
            fin>>a>>b;g.addEdge(a,b);
            vertex--;
        }
    }
    g.connectedComponents(); 
    fin.close();
    return 0;
}