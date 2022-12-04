#include <bits/stdc++.h>
using namespace std;
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct Stack
{
    int item[STACKSIZE];
    int top;
};
 Stack s;
int Isempty(){
    if(s.top==-1)
    return TRUE;
    else
    return FALSE;
}
void push(int x)
{   
    if(s.top== STACKSIZE-1)
    cout<<"STACK OVER FLOW"<<endl;
    s.top++;
    s.item[s.top]=x;
}
int pop(){
    int x;
    if(Isempty())
    cout<<"STACK UNDER FLOW"<<endl;
    x=s.item[s.top];
    s.top--;
    return x;

}
int binary(int n){
    int rem;
     while(n!=0){
        rem=n%2;
        push(rem);
        n=n/2;
     }
}
int main(){
    int n,x;
    cin>>n;
    binary(n);
    cout<<"binary numbers are => ";
    while (s.top!=0)
    {
      x=pop();
      cout<<x<<" ";
      
    }
    return 0;
}
