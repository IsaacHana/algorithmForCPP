#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score;
    cin >> score;

    if (100 >= score && score >= 90)
        cout << "A";
    else if (90 > score && score >= 80)
        cout << "B";
    else if (80 > score && score >= 70)
        cout << "C";
    else if (70 > score && score >= 60)
        cout << "D";
    else
        cout << "F";
}