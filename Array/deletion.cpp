#include<bits/stdc++.h>
using namespace std;
int del(int arr[],int n){
     for (int i = 0; i <5; i++)
    {
        if(i==(n-1)){
        arr[i]=arr[i+1];
        n++;
        }
    }
  return arr[4];
}
int main (){
    int arr[5]={1,2,3,5,6};
      int n;
    cin>>n;
    del(arr,n);
    for(int i= 0;i<4;i++){
        cout<< arr[i]<<" ";
    }
 return 0;
}
