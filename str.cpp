#include <bits/stdc++.h>
using namespace std;

struct student
{
    int rollno;
    int section;
    float percentage;
    int mobileno;
};
int main(){
    int n;
    cin>>n;
    struct student s[n];
    for (int i = 0; i <n; i++)
    cin>>s[i].rollno>>s[i].section>>s[i].percentage>>s[i].mobileno;
    for (int i = 0; i <n; i++)
    cout<<s[i].rollno<<" "<<s[i].section<<" "<<s[i].percentage<<" "<<s[i].mobileno<<endl;
    return 0;
}