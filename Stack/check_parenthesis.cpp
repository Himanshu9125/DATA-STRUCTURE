#include <bits/stdc++.h>
using namespace std;

stack<char> s;
void paranthesis(string c)
{
    int i = 0;
    while (c[i]!='\0')
    {
        if (c[i] == '(')
            s.push(c[i]);
        else{
            if(!s.empty())
            s.pop();
            else
            s.push(c[i]);
        }
        i++;
    } 
    if (s.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int main()
{
    string c;
        cin >> c;
    paranthesis(c);
    return 0;
}
