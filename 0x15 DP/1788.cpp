#include <bits/stdc++.h>
using namespace std;

int n;
int d[1'000'002];
int mod = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 0;
    d[1] = 1;

    if (n >= 0) {
        for (int i = 2; i <= n; i++) {
            d[i] = (d[i - 1] + d[i - 2]) % mod;
        }
    } else {
        n = abs(n);
        for (int i = 2; i <= n; i++) {
            d[i] = (d[i - 2] - d[i - 1]) % mod;
        }
    }

    if (d[n] > 0)
        cout << "1\n";
    else if (d[n] < 0)
        cout << "-1\n";
    else
        cout << "0\n";

    cout << abs(d[n]);
}