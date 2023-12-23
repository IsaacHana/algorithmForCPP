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
    cout << "result"
         << "\n";
    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        int cnt = 1;
        //
        while (!S.empty() && S.top().first <= h)
        {
            ans += S.top().second;
            if (S.top().first == h)
                cnt += S.top().second; // ?
            S.pop();
        }
        //
        if (!S.empty())
            ans++;
        S.push({h, cnt});
        cout << ans << "\n";
    }

    // cout << ans;
}