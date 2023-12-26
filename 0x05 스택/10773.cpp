#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int K, ans = 0;
    cin >> K;
    while (K--)
    {
        int val;
        cin >> val;
        if (val == 0)
        {
            S.pop();
        }
        else
        {
            S.push(val);
        }
    }

    while (!S.empty())
    {
        ans += S.top();
        S.pop();
    }

    cout << ans;
}