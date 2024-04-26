#include <bits/stdc++.h>
using namespace std;

int N;
int d[1'000'000];
int mod = 15'746;

// 1 : 1 : 1
// 2 : 00, 11 : 2
// 3 : 001, 100, 111 : 3
// 4 : 0011, 0000, 1001, 1100, 1111 : 5

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= N; i++) d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[N] << '\n';
}