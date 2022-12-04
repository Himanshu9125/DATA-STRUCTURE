#include <iostream>
using namespace std;
void lenear_search(int arr[],int n){
    int ele;
    cin>>ele;
    for (int i = 0; i < n; i++)
    {
        if(ele==arr[i]){
            cout<<i<<" "<<arr[i];
            break;
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
   lenear_search(arr,n)    ;
   return 0;
}


    
