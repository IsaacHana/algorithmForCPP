#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2'002], d[2'002][2'002];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // tabulation
    for (int i = 1; i <= n; i++) {
        d[i][i] = 1;
        // a[] 0 1 1 1
        // d[][]
        // 0 0 0 0
        // 0 1 1 0
        // 0 0 1 1
        // 0 0 0 1
        if (a[i - 1] == a[i]) d[i - 1][i] = 1;  // 2개짜리 펠린드롬 // ex) s = 1, e = 2
    }

    for (int gap = 2; gap < n; gap++) {
        for (int i = 1; i <= n - gap; i++) {
            int s = i, e = i + gap;
            if (a[s] == a[e]) {         // 시작 지점과 끝 지점의 수가 같은가?
                if (d[s + 1][e - 1]) {  // 사이에 있던 것이 펠린드롬 이었는가?
                    // ex 2, 6
                    // 0 1 2 1 3 1 2 1
                    // 0 0 0 0 0 0 0 0
                    // 0 1 0 0 0 0 0 0
                    // 0 0 1 0 0 0 1 0
                    // 0 0 0[1 0 1]0 0
                    d[s][e] = 1;
                }
            }
        }
    }

    // result
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << "\n";
    }
}