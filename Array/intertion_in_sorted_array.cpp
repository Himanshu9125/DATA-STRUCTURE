#include<bits/stdc++.h>
using namespace std;
int main (){
    int arr[5]={1,2,3,5,6};
      int n;
    cin>>n;
    int k;
    for (int i = 0; i <=5; i++)
    {
        if(n<arr[i]){
        k=arr[i];
        arr[i]=n;
        n=k;
        }
    }
    for(int i= 0;i<=5;i++){
        cout<< arr[i]<<" ";
    }

}
