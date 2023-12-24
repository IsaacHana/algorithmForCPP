#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        stack<pair<long long, long long>> S;
        long long ans = 0;

        for (int i = 0; i < N; i++)
        {
            int h;
            cin >> h;
            int idx = i;
            while (!S.empty() && S.top().first >= h)
            {
                int w = i - S.top().second;
                ans = max(ans, w * S.top().first);
                idx = S.top().second;
                S.pop();
            }
            S.push({h, idx});
        }

        while (!S.empty())
        {
            ans = max(ans, (N - S.top().second) * S.top().first);
            S.pop();
        }

        cout << ans << "\n";
    }
}