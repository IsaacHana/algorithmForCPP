#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[201] = {};

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp + 100]++;
    }
    int cnt;
    cin >> cnt;

    cout << arr[cnt + 100];
}