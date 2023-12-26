#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N];
    int ans[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    stack<int> S;
    for (int i = N - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top() <= arr[i])
        {
            S.pop();
        }

        if (S.empty())
            ans[i] = -1;
        else
        {
            ans[i] = S.top();
        }
        S.push(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}