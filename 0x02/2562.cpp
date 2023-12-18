#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0, maxIndex;

    for (int i = 1; i <= 9; i++)
    {
        int current;
        cin >> current;
        if (current > max)
        {
            max = current;
            maxIndex = i;
        }
    }

    cout << max << '\n';
    cout << maxIndex << '\n';
}