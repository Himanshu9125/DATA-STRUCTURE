#include <iostream>
using namespace std;
void binary_search(int arr[],int n){
    int ele;
    cin>>ele;
    int mid,h,l;
    h=n-1;
    l=0;
    int i=0;
    while (l<h)
    {
       mid=(h+l)/2;
       if (arr[mid]==ele){
       cout<<mid;
        break;
       }
       else{
        if(arr[mid]>ele){
            h=mid-1;
        
        }
        else{
            l=mid+1;
        }
       }

    }
    
    
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
   binary_search(arr,n)    ;
   return 0;
}


    
