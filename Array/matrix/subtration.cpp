#include <bits/stdc++.h>
using namespace std;

int add(int m1[20][20], int m2[20][20], int m3[20][20], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            m3[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return m3[20][20];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int m1[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> m1[i][j];
        }
    }
    int m3[20][20] = {0};
    int m2[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> m2[i][j];
        }
    }
    add(m1, m2, m3, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
