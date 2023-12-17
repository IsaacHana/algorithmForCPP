#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0, year;
    cin >> year;

    if (year % 4 == 0)
    {
        if (year % 400 == 0)
        {
            answer = 1;
        }
        else if (year % 100 != 0)
        {
            answer = 1;
        }
    }

    cout << answer;
}