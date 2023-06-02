#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void dfs_visited(int i, vector<int> &visited, vector<int> adj_list[],vector<int>&prdc)
{
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < adj_list[i].size(); j++)
    {
        if (visited[adj_list[i][j]] == 0)
        {
            dfs_visited(adj_list[i][j], visited, adj_list,prdc);
            prdc[adj_list[i][j]] = i;
        }
    }
}

void DFS(vector<int> adj_list[], int n )
{
    vector<int> visited(n, 0);
    vector<int>prdc(n,-1);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0){
            dfs_visited(i, visited, adj_list,prdc);
        }
    }
    int count =0;
    cout<<endl;
    for(int i=0;i<n;i++){
       cout<<prdc[i]<<",";
        if(prdc[i]==-1){
          count++;
        }
    }
    cout <<endl<< count << endl;
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
    cout << "DFS order =";

    DFS(adj, n);
    return 0;
}
