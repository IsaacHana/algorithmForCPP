#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[26] = {};
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;
    for (auto c : s1)
    {
        arr[c - 'a']++;
    }

    for (auto c : s2)
    {
        arr[c - 'a']--;
    }

    for (int i : arr)
    {
        ans += abs(i);
    }

    cout << ans;
}