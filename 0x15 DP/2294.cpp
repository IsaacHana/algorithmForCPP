#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[102], d[10'002];
int main(void) {
    // prep
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // min memoization
    fill(d, d + 10'002, 100'002);
    d[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            d[j] = min(d[j], d[j - a[i]] + 1);
        }
    }
    // result
    cout << (d[k] == 100'002 ? -1 : d[k]);
}