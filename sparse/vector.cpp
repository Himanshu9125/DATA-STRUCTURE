#include <bits/stdc++.h>
using namespace std;

struct svector
{
    int row;
    int clm;
    int data;
}v[100];

void vector_form(vector<int> m[], int n )
{
    //struct svector v;
    int k=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(m[i][j]!=0){
                v[k].row=i;
                v[k].clm=j;
                v[k].data=m[i][j];
                k++;
            }
        }
    }
     cout<<"Row"<<" "<<" Column"<<" "<<"Data"<<endl;
    for (int i = 0; i < k; i++)
    {
        cout << v[i].row << "     " << v[i].clm << "       " << v[i].data<<endl;
    }
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> m[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            m[i].push_back(x);
        }
    }
    vector_form(m, n);
}