#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int d[100'002];

    // 1 (2) 3 4 5 6 7 (8) 9 10 11
    // 1 (2) 3 1 2 3 4 (2) 1 2  3
    //        4+1,4+2... 9+1

    for (int i = 1; i <= n; i++) {
        d[i] = i;
        for (int j = 1; j * j <= i; j++) {
            d[i] = min(d[i], d[i - (j * j)] + 1);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << d[i] << " ";
    // }

    cout << d[n] << '\n';
}