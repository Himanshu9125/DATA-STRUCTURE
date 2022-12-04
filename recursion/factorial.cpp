#include<iostream>
using namespace std;
int fact(int k){
 int y=1;
 for (int i =1; i <=k; i++)
 {
    if(i>1){
    y=y*i;
    }
 }
 return y;
}


int main(){
    int n;
    cin>>n;
     int sum=fact(n);
     cout <<sum;
    return 0;
}
