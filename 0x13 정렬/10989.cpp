#include <bits/stdc++.h>
using namespace std;

int N;

int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        arr[val] += 1;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) cout << i << '\n';
    }
}