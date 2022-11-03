#include<bits/stdc++.h>
using namespace std;

struct marks
{
    int chemistry;
    int maths;
    int physics;
    float percentage;
};
int main(){
struct marks m[5];
for (int i = 0; i < 5; i++)
{
    cin>>m[i].chemistry>>m[i].maths>>m[i].physics;
   
}
for(int i=0;i<5;i++){
 float x=((m[i].chemistry+m[i].maths+m[i].physics)/300)*100;
    m[i].percentage=x;
}
for (int i = 0; i < 5; i++)
{
    cout<< m[i].percentage<<endl;
}
return 0;
}