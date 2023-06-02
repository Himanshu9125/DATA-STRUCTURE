#include<bits/stdc++.h>
using namespace std;

int main(){
    int edg,n;
    cout<<" enter the number of edge"<<endl;
    cin>>edg;
    cout<<"enter the number of vertex"<<endl;
    cin>>n;

    vector<int>adj[n];
        for(int j=1;j<=edg;j++){
            int a , b ;
            cout<<"end point of edge"<<j<<":";
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<<"adjusent list"<<endl;
    for (int i = 0; i<n; i++)
    {
            cout << i << ":";
         for (int j = 0; j < adj[i].size(); j++)
            {

                cout << adj[i][j] << ",";
            }
        cout<<endl;
    }
    cout<<"matrix=>"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                if (adj[i][j] > 9 || adj[i][j] <0)
                    cout << " 0";
                else
                 cout<<" 1";
        }
        cout << endl;
    }
}