#include <bits/stdc++.h>
using namespace std;
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct Stack
{
    char item[STACKSIZE];
    int top;
};
struct Stack s;
int Isempty()
{
    if (s.top == -1)
        return TRUE;
    else
        return FALSE;
}
void push(int x)
{
    if (s.top == STACKSIZE - 1)
        cout << "STACK OVER FLOW" << endl;
    s.top++;
    s.item[s.top] = x;
}
int pop()
{
    int x;
    if (Isempty() == -1)
        cout << "STACK UNDER FLOW" << endl;
    x = s.item[s.top];
    s.top--;
    return x;
}
int hexa(int n)
{
    char m=65;
    int rem;
    while (n != 0)
    {
        rem = n % 16;
        if (rem >= 10){
            m=m+(rem-10);
            push(m);

        }
        else{
            push(rem);
        }                   
             n = n / 16;
    }
}
int main()
{
    int n, x;
    cin >> n;
    int t = n;
    hexa(n);
    cout << "binary numbers are => ";
    while (t != 0)
    {
        x = pop();
        cout << x << " ";
        t = t / 16;
    }
    return 0;
}
