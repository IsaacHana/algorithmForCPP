#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26];
    fill(arr, arr + 26, 0);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        int index = str.at(i) - 'a';
        arr[index]++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
}