#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int n, int low, int high)
{
     int m;
    int z;
    m=(low+high)/2;
    z =a[low];
    a[low]=a[m];
    a[m]=z;
    int i = low;
    int j = high + 1;
    int pivot = a[low];
    int t;
    int k;
    do
    {
        do
        {
            i=i+1;
        } 
        while (a[i] < pivot);
         do
        {
            j=j-1;
        }
        while (a[j] > pivot);
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    } 
    while (i < j);
     k=a[j];
    a[j]=a[low];
    a[low]=k;
  return j;
}

void mid_quick(int a[],int n,int low,int high){
   
      if (low < high)
    {
        int j = partition(a,n, low, high);
        mid_quick(a,n, low, j - 1);
        mid_quick(a,n, j + 1, high);
    }
}
int main(){
    int high,low;
    int n;
    cin>>n;
    high=n-1;
    low=0;    
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mid_quick(a,n,low,high);
  
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;

}
