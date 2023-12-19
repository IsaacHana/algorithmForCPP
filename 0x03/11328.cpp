#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str, frystr, ans = "Possible";
        cin >> str >> frystr;
        int arr[26] = {};

        for (auto current : str)
        {
            arr[current - 'a']++;
        }

        for (auto current : frystr)
        {
            arr[current - 'a']--;
        }

        for (int j : arr)
        {
            if (j != 0)
                ans = "Impossible";
        }

        cout << ans << "\n";
    }
}