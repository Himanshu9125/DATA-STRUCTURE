#include<bits/stdc++.h>
using namespace std;
stack<char>s;
string reverstr(string c){
    int i=0,j=0;
     while (c[i]!='\0')
     {
       s.push(c[i]);
        i++;
     }
    while (!s.empty())
    {
       c[j]=s.top();
       j++;
      s.pop();
    }
     return c;
     
}
int main(){
    string c;
    cin>>c;
    cout<<reverstr(c)<<endl;
    return 0;
}
