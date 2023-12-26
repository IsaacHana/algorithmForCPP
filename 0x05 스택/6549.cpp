#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        stack<pair<long long, long long>> S;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            int idx = i;
            while (!S.empty() && S.top().second >= h)
            {
                int w = i - S.top().first;
                ans = max(ans, w * S.top().second);
                idx = S.top().first;
                S.pop();
            }
            S.push({idx, h});
        }

        while (!S.empty())
        {
            int w = n - S.top().first;
            ans = max(ans, w * S.top().second);
            S.pop();
        }

        cout << ans << '\n';
    }
}