#include<iostream>
using namespace std;
int fab(int n){
    if(n==1){
        return 0;
    }
    else{
      if(n==2){
        return 1;
      }
      else{
        return fab(n-1)+fab(n-2);
      }
    }
}
int main(){
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
     k=fab(i);
    cout<<k<<" ";
    }
    return 0;
}
