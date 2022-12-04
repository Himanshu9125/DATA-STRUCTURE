#include <iostream>
using namespace std;
int multiply(int a[3][3], int b[3][3], int c[3][3])
{
    int t = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int j = 0; j < 3; j++)
            {
                t = t + a[i][j] * b[j][i];
            }
            c[i][j] = t;
            t=0;
        }
       
    }
    return c[3][3];
}
int main()
{
    int a[3][3];
    int b[3][3];
    int c[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> b[i][j];
        }
    }
    multiply(a, b, c);
    cout << " multiplication:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
