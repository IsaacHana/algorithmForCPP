#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, ans = 0;
    cin >> N >> K;

    int arr[7][2] = {};
    for (int i = 0; i < N; i++)
    {
        int gender, grade;
        cin >> gender >> grade;
        arr[grade][gender]++;
    }

    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans += arr[i][j] / K;
            if (arr[i][j] % K != 0)
                ans++;
        }
    }

    cout << ans;
}