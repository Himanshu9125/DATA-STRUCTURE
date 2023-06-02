#include<bits/stdc++.h>
using namespace std;

void apsflloyed(int n,vector<int>w[])
{
    int d[n][n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++ ){
            if(w[i][j]==0){
                if(i!=j){
                    d[i][j]=INT_MAX/2;
                }
            }
            else{
                d[i][j]=w[i][j];
            }
        } 
    }
    for(int k=0;k<n;k++){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
              int x=d[i][j];
              int y=d[k][j]+d[i][k];
              d[i][j]=min(x,y);

            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> w[n];
     for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            w[i].push_back(x);
        }
    }
    apsflloyed(n,w);
}