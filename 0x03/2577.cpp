#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    long long result;
    string str_ans;

    cin >> A >> B >> C;
    result = A * B * C;
    int arr[10];
    fill(arr, arr + 10, 0);

    while (result > 0)
    {
        arr[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}