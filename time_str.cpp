#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct time
{
    int hr;
    int min;
    int sec;
};
int main(){
    struct time h1={7,31,54};
    struct time h2={2,55,36};
    struct time h;
    h.sec=(h1.sec + h2.sec)%60;
    int x=(h1.sec + h2.sec)/60;
    h.min=(h1.min + h2.min + x)%60;
    int y=(h1.min + h2.min + x)/60;
    h.hr=(h1.hr + h2.hr +y);
    cout<<h.hr<<" "<<h.min<<" "<<h.sec<<endl;
    return 0;
}