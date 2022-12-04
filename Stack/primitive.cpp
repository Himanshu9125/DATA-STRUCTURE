#include <bits/stdc++.h>
using namespace std;
#define size 20;
struct Stack
{
    int data[20];
    int top;
};
Stack s;
void intialize(struct Stack *s)
{
    (*s).top = -1;
}
int Isempty(struct Stack *s)
{
    if ((*s).top == -1)
        return true;
    else
        return false;
}
void push(struct Stack *s, int x)
{
    if ((*s).top == 20)
        cout << "Stack over flow" << endl;
    (*s).top++;
    (*s).data[s->top] = x;
}
int pop(struct Stack *s)
{
    int x;
    if (Isempty(&(*s)))
        cout << "stack underflow" << endl;
    x = (*s).data[s->top];
    (*s).top--;
    return x;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i <n; i++)
    {
       s.push(arr[i]);
    }
  cout<<s.pop()<<" ";
  while (!Isempty)
    {
       cout<<s.pop()<<" ";
    }
    return 0;
}
