#include <bits/stdc++.h>
using namespace std;

stack<char> s,p,h;
void paranthesis_brackets(string c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '(')
            s.push(c[i]);
        else
        {
            if (c[i] == ')')
                s.pop();
            else
            {
                if (c[i] == '{')
                    p.push(c[i]);
                else
                {
                    if (c[i] == '}')
                        p.pop();
                    else
                    {
                        if (c[i] == '[')
                            h.push(c[i]);
                        else
                            h.pop();
                    }
                }
            }
        }
        i++;
    }
    if (s.empty()&& p.empty() && h.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    string c;
    cin >> c;
    paranthesis_brackets(c);
    return 0;
}
