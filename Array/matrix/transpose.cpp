#include<iostream>
using namespace std;
void transpose(int a[][3]){
    int b;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (i > j)
            {
                b = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = b;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << " " << endl;
    }
}
int main(){
    int a[3][3];
    int b;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            cin>>a[i][j];
        }   
    }
    transpose(a);
return 0;
}
