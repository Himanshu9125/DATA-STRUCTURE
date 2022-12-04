#include<bits/stdc++.h>
using namespace std;
stack<int>s;
void maximum(int arr[],int n){
    int i=1;
    s.push(arr[0]);
    while (i<n)
    {
        if(arr[i]>s.top()){
          s.pop();
          s.push(arr[i]);
          i++;
        }
         else
         i++;
    }
      cout <<s.top();
}
void minimum(int arr[], int n)
{
  int i = 1;
  s.push(arr[0]);
  while (i < n)
  {
    if (arr[i] < s.top())
    {
      s.pop();
      s.push(arr[i]);
      i++;
    }
    else
      i++;
  }
  cout << s.top();
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
      s.push( arr[i]);
    }
    maximum(arr,n);
    cout<<endl;
    minimum(arr,n);
    return 0;
}
