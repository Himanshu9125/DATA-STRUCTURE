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

/*-------------------------------------------------------------------------------------*/
void any_base(struct Stack *s, int n, int b)
{
    int ans,x;
    while (n != 0)
    {  
        if(n<10){
        ans = n % b;
        push(&(*s), ans);
        n = n / b;
        }
        else{
            ans = n % b;
            push(&(*s), ans+55);
            n = n / b;
        }
    }
    while (!Isempty(&(*s)))
    {
        x = pop(&(*s));
        if (x >= 10)
        {
            cout << char(x) << " ";
        }
        else
        {
            cout << x << " ";
        }
    }
}
int main()
{
    int  b;
    int n;
    cin >> n >> b;
    intialize(&s);
  
    any_base(&s,n,b);
    
    cout << endl;
}
