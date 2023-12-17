#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, total = 0, oddCnt = 0, min = 100;
    for (int i = 0; i < 7; i++)
    {
        cin >> x;

        bool isOdd = x & 1;

        if (isOdd)
        {
            oddCnt += 1;
            total += x;

            if (x < min)
            {
                min = x;
            }
        }
    }

    if (oddCnt)
    {
        cout << total << '\n';
        cout << min;
    }
    else
    {
        cout << -1;
    }
}
