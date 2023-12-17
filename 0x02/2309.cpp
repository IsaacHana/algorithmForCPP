#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int N = 9, M = 7;

    int arr[N], result[M];

    int total = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    sort(arr, arr + N);

    for (int a = 0; a < N - 1; a++)
    {
        for (int b = a + 1; b < N; b++)
        {
            if (total - arr[a] - arr[b] == 100)
            {
                for (int c = 0, pointer = 0; c < N; c++)
                {
                    if (a == c || b == c)
                        continue;
                    result[pointer++] = arr[c];
                }
            }
        }
    }

    for (int i = 0; i < M; i++)
        cout << result[i] << '\n';
}