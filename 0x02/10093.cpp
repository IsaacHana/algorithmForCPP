#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;
    if (A > B)
    {
        swap(A, B);
    }
    if (A == B || B - A - 1 == 0)
    {
        cout << 0;
    }
    else
    {
        cout << B - A - 1 << '\n';
        while (A < B - 1)
        {
            cout << ++A << " ";
        }
    }
}