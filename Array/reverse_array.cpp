#include <bits/stdc++.h>
using namespace std;
void reverse_array(int a[], int n)
{
    int j = 0, e = n - 1;
    while (j <= e)
    {
        int temp = a[j];
        a[j++] = a[e];
        a[e--] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    reverse_array(a, n);
}
