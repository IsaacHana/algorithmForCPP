#include <bits/stdc++.h>
using namespace std;

int sum(int arr[])
{
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += arr[i];
    }
    return total;
}

int calculateAvg(int arr[])
{
    return sum(arr) / 5;
}

int calculateMid(int arr[])
{
    sort(arr, arr + 5);
    return arr[2];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << calculateAvg(arr) << '\n';
    cout << calculateMid(arr);
}