#include<bits/stdc++.h>
using namespace std;
void missing(int a[],int n,int b[],int x,int y){
    for(int i=0; i<n-1;i++){
        if(a[i]+y!= a[i+1]){
            b[x]=a[i]+y;
            x++;
            
        }
    }
    for (int j = 0; j < x; j++)
    {
        cout << b[j] << " ";
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    int y=a[1]-a[0];
    int k=0;
    int b[k];
     missing(a,n,b,k,y);
  return 0;
}
