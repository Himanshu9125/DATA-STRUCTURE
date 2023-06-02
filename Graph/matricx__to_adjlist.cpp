#include<bits/stdc++.h>
using namespace std;

void list_mat(vector<vector<int>>adjlist[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (adjlist[i][j]==0)
                cout << 0 << " ";
            else
            cout<<1<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int edg,vtx;
    cin>>edg>>vtx;
    vector<vector<int>>v;
    for (int i = 0; i <edg; i++)
    {
        for (int j = 0; j <vtx; j++)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
    }
    list_mat(v,vtx);
}