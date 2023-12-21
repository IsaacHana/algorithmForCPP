#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    stack<int> S;

    while (K--)
    {
        int val;
        cin >> val;
        if (val)
        {
            S.push(val);
        }
        else
        {
            S.pop();
        }
    }

    int total = 0;

    while (!S.empty())
    {
        total += S.top();
        S.pop();
    }

    cout << total;
}