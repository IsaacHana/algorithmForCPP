#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<pair<int, int>> S;
    long long ans = 0;
    while (N--)
    {
        int h, cnt = 1;
        cin >> h;
        while (!S.empty() && S.top().first <= h)
        {
            ans += S.top().second;
            if (S.top().first == h)
            {
                cnt += S.top().second;
            }
            S.pop();
        }
        if (!S.empty())
        {
            ans++;
        }
        S.push({h, cnt});
    }
    cout << ans;
}