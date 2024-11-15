#include <bits/stdc++.h>
using namespace std;

int n;
int a[5'002], d[5'002];
int mod = 1'000'000;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // prep
    string s;
    cin >> s;
    n = s.size();

    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    // memoizaion
    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) d[i] = (d[i] + d[i - 1]) % mod;
        int x = a[i - 1] * 10 + a[i];
        if (x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
    }
    // result
    cout << d[n];
}