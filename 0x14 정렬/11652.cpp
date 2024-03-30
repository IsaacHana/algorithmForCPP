#include <bits/stdc++.h>
using namespace std;

long long a[100'002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);
    int cnt = 0;
    long long val = -(1ll << 62) - 1;
    int mxcnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || a[i - 1] == a[i])
            cnt++;
        else {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                val = a[i - 1];
            }
            cnt = 1;
        }
    }

    if (cnt > mxcnt) val = a[N - 1];

    cout << val << '\n';
}