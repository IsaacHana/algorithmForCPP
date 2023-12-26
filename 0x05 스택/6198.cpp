#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int N;
    long long ans;

    cin >> N;
    while (N--)
    {
        int h;
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