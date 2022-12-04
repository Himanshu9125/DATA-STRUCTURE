#include<bits/stdc++.h>
using namespace std;
stack<char>s;
void reverstr(string c){
    int i=0,j=0;
    string k;
     while (c[i]!='\0')
     {
       s.push(c[i]);
        i++;
     }
     
}
int main(){
    string c;
    cin>>c;
    int i=0;
    reverstr(c);
    while(!s.empty()){
      if(c[i]==s.top()){
       s.pop();
       i++;
      }
      else{
        break;
      }
    }
    if(s.empty())
    cout<<"palidrome"<<endl;
    else
        cout << "not palidrome" << endl;
    return 0;
}
