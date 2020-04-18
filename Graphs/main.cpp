#include<bits/stdc++.h>
using namespace std;
void list_directed()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  vector<int> v[vertex+1];
  cout<<"Enter edges"<<"\n";

  int u,w;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    v[u].push_back(w);
  }

  for(int i=1;i<=vertex;i++)
  {
    cout<<i<<"-->"<<" ";
    for(int j=0;j<v[i].size();j++)
    {
      cout<<v[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void list_undirected()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  vector<int> v[vertex+1];
  cout<<"Enter edges"<<"\n";

  int u,w;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    v[u].push_back(w);
    v[w].push_back(u);
  }

  for(int i=1;i<=vertex;i++)
  {
    cout<<i<<"-->"<<" ";
    for(int j=0;j<v[i].size();j++)
    {
      cout<<v[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void matrix_directed()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  cout<<"Enter edges"<<"\n";
  int mat[vertex+1][vertex+1]={0};

  int u,w;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    mat[u][w]=1;
  }

  for(int i=1;i<=vertex;i++)
  {
    for(int j=1;j<=vertex;j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void matrix_undirected()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  cout<<"Enter edges"<<"\n";

  int mat[vertex+1][vertex+1]={0};

  int u,w;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    mat[u][w]=1;
    mat[w][u]=1;
  }
  for(int i=1;i<=vertex;i++)
  {
    for(int j=1;j<=vertex;j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void incidence_directed()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  cout<<"Enter edges"<<"\n";

  int graph[vertex+1][edge]={0};

  int u,w,edge_count=0;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    graph[u][edge_count]=1;
    edge_count++;
  }

  for(int i=1;i<=vertex;i++)
  {
    for(int j=0;j<edge;j++)
    {
      cout<<graph[i][j]<<" ";
    }
    cout<<"\n";
  }

}
void incidence_undirected()
{
  int vertex,edge;
  cout<<"Enter vertices and edges"<<"\n";
  cin>>vertex>>edge;

  cout<<"Enter edges"<<"\n";

  int graph[vertex+1][edge]={0};

  int u,w,edge_count=0;
  for(int i=0;i<edge;i++)
  {
    cin>>u>>w;
    graph[u][edge_count]=1;
    graph[w][edge_count]=1;
    edge_count++;
  }

  for(int i=1;i<=vertex;i++)
  {
    for(int j=0;j<edge;j++)
    {
      cout<<graph[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void directed()
{
  cout<<"1. Using adjacency list"<<"\n";
  cout<<"2. Using ajacency matrix"<<"\n";
  cout<<"3. Using incidence matrix"<<"\n";

  int input;
  cin>>input;

  if(input==1)
  {
    list_directed();
  }
  if(input==2)
  {
    matrix_directed();
  }
  if(input==3)
  {
    incidence_directed();
  }
}

void undirected()
{
  cout<<"1. Using adjacency list"<<"\n";
  cout<<"2. Using ajacency matrix"<<"\n";
  cout<<"3. Using incidence matrix"<<"\n";

  int input;
  cin>>input;

  if(input==1)
  {
    list_undirected();
  }
  if(input==2)
  {
    matrix_undirected();
  }
  if(input==3)
  {
    incidence_undirected();
  }
}
int main()
{
  cout<<"Welcome to Graph World"<<"\n";
  cout<<"1. For directed Graph"<<"\n";
  cout<<"2. For undirected Graph"<<"\n";

  int type;
  cin>>type;

  if(type==1)
  {
    directed();
  }
  if(type==2)
  {
    undirected();
  }
  return 0;
}
