#include <bits/stdc++.h>
using namespace std;

int num_arr[1000001] = {};
bool occur[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num_arr[i];
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        int dif = x - num_arr[i];
        if (dif > 0 && occur[dif])
            ans++;
        occur[num_arr[i]] = true;
    }

    cout << ans;
}