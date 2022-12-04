 #include<iostream>
using namespace std;
int bs(int a,int arr[],int n,int l,int m,int h){
    h=n-1;
    if(l>h){
        return -1;
    }
    else{
       if(l<h){
        m=(l+h)/2;
        if(arr[m]==a){
            return m;
        }
        else{
            if(a<arr[m]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
       }
    }
}
int main(){
    int n,k ,a,l=0,m,h;
    cin>>a>>n;
    int arr[n];
    k=bs(a,arr,n,l,m,h);
    cout<<k<<endl;
}
