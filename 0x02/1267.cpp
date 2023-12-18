#include <bits/stdc++.h>
using namespace std;

int calculateYoungSik(int time)
{
    return ((time / 30) + 1) * 10;
}

int calculateMinSik(int time)
{
    return ((time / 60) + 1) * 15;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N];
    int Y = 0, M = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        Y += calculateYoungSik(arr[i]);
        M += calculateMinSik(arr[i]);
    }

    if (Y < M)
    {
        cout << "Y " << Y;
    }
    else if (M < Y)
    {
        cout << "M " << M;
    }
    else
    {
        cout << "Y M " << Y;
    }
}