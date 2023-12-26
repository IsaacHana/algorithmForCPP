#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> S;
    S.push({1000000001, 0});
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int h;
        cin >> h;

        while (S.top().first <= h)
        {
            S.pop();
        }
        cout << S.top().second << " ";
        S.push({h, i});
    }
}