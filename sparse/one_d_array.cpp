#include <bits/stdc++.h>
using namespace std;

void one1_D(vector<int> m[], int n,int row,int clm)
{
    vector<int> arr;


      
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] != 0)
            {
                arr.push_back(m[i][j]);
            }
        }
    }
   for (int i = 0; i < arr.size(); i++)
   {
       cout << arr[i] << " ";
   }
   cout<<endl;
   int x=((row+1)*(row)/2)+clm+1;
   cout<<arr[x]<<endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int>m[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            m[i].push_back(x);
        }
    }
    
    int row,clm;
    cin>>row>>clm;

    one1_D(m, n,row,clm);
}