#include<iostream>
using namespace std;
int power(int a,int n){
    if(n==0){
        return 1;
    }
    else{
       return (a*power(a,n-1));
    }
}
int main(){
    int n,k ,a;
    cin>>a>>n;
    k=power(a,n);
    cout<<k<<endl;
}
