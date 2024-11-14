#include <bits/stdc++.h>
using namespace std;

int T;          // (1 <= T <= 10)
int N;          // (1 <= N <= 20)
int M;          // (1 <= M <= 10,000)
int d[10'002];  // dp
int money[22];  // µ·
int cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        fill(d, d + 10'002, 0);
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> money[i];
        }

        cin >> M;
        d[0] = 1;   
        for (int i = 0; i < N; i++) {
            for (int j = money[i]; j <= M; j++) {
                d[j] += d[j - money[i]];
            }
        }

        cout << d[M] << "\n";
    }
}