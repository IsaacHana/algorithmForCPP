#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> S;
    int N;
    cin >> N;
    S.push({0, 100000001});
    for (int i = 1; i <= N; i++)
    {
        int val;
        cin >> val;
        while (!S.empty() && S.top().second <= val)
        {
            S.pop();
        }
        if (!S.empty())
        {
            cout << S.top().first << " ";
        }

        S.push({i, val});
    }
}