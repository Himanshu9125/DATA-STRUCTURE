#include <bits/stdc++.h>
using namespace std;

void slection(int a[], int n)
{
    int x=n;
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        while (j < x)
        {
            if (a[i] > a[j])
            {
                k = j;
                swap(a[i], a[k]);
            }
                j++;
             
        }
        i++;
        j=i;
    }
    for(int l=0;l<n;l++){
        cout<<a[l]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    slection(a,n);
    return 0;
}
