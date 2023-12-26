#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<long long> S;
    long long ans = 0;
    int N;
    cin >> N;
    while (N--)
    {
        int h, cnt = 1;
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