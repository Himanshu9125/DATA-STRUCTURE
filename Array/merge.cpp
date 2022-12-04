#include <iostream>
using namespace std;
int merge(int a[],int m ,int b[],int n,int c[],int x)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < m) && (j < n))
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    return c[x];
}
int main()
{
    int m,n;
    cin>>m>>n;
    int c[m+n];
    int a[m] ;
    int b[n] ;
    for (int i = 0; i < m; i++)
    {
      cin>>a[i];
    }
    for (int j = 0; j < m; j++)
    {
      cin>>b[j];
    }
     merge(a,m, b,n,c,m+n);
     for (int i = 0; i <m+n; i++)
     {
        cout<<c[i]<<" ";
     }
     
    return 0;
}
