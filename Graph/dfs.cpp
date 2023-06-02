#include<bits/stdc++.h>
using namespace std;


int dfs_visited(int i,vector<int>&visited,vector<int>adj_list[],int element){
      cout<<i<<" ";
      visited[i]=1;
      for(int j=0;j<adj_list[i].size();j++){
        if(visited[adj_list[i][j]]==0){
          
           element+=dfs_visited(adj_list[i][j],visited,adj_list,element)+1;
        }
      }
      return element;
}

void DFS(vector<int>adj_list[],int n){
    vector<int>visited(n,0);
    vector<int>v;
     int element;
       for(int i=0;i<n ;i++){
          if(visited[i]==0){
            element=0;
            element= dfs_visited(i,visited,adj_list,element)+1;
            v.push_back(element);
          }
      }
      cout<<endl;
      for (int i = 0; i < v.size(); i++){
        cout<<"no of element="<<i<<":"<<v[i]<<" ";
      }
      cout<<endl;
      cout<<"number of component="<<v.size();
}

int main()
{
      int edg, n;
      cout << " enter the number of edge" << endl;
      cin >> edg;
      cout << "enter the number of vertex" << endl;
      cin >> n;

      vector<int> adj[n];
      for (int j = 1; j <= edg; j++)
      {
          int a, b;
          cout << "end point of edge" << j << ":";
          cin >> a >> b;
          adj[a].push_back(b);
      }
      cout << "adjusent list" << endl;
      for (int i = 0; i < n; i++)
      {
          cout << i << ":";
          for (int j = 0; j < adj[i].size(); j++)
          {
            cout << adj[i][j] << ",";
          }
          cout << endl;
      }
      cout<<"DFS order = " ;
      DFS(adj, n);
      return 0;
}