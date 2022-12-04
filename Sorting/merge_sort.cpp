#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int n,int low,int mid,int high){
   int i=low;
    int j=mid+1;
    int k=low; 
    int c[high+1];
    while ((i<=mid)&& (j<=high))
    {
        if(a[i]<a[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
           if(a[i]>a[j])
           {
            c[k]=a[j];
            j++;
            k++;
           }

        }

    }
    while (i<=mid)
    {
        c[k]=a[i];
        i++;
        k++;
    }
      while (j<=high)
    {
        c[k]=a[j];
        j++;
        k++;
    }
    for (int i = 0; i <=high; i++)
    {
        a[i]=c[i];
        
    }
    for (int i = 0; i <=high; i++)
    {
        cout<<a[i]<<" ";
    } 
}
int  merge_sort(int a[],int n,int low, int high){
     if(low==high)
     return 0 ;
     else
     {
        int  mid=(low+high)/2;
        merge_sort(a,n,low,mid);
        merge_sort(a,n,mid+1,high);
        merge(a,n,low,mid,high);
     }

     
}
int main(){
    int n,low,high;
    cin>>n;
    high=n-1;
    low=0;
    int a[n];
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    
    merge_sort(a,n,low,high);
    return 0;

}
