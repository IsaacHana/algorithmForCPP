#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long ans = 0;
    stack<long long> S;

    cin >> N;

    while (N--)
    {
        long long h;
        cin >> h;

        while (!S.empty() && S.top() <= h)
        {
            S.pop();
        }

        ans += S.size();

        S.push(h);
    }

    cout << ans;
}