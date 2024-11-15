#include <bits/stdc++.h>
using namespace std;

int n;
int d[32];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // prep
    cin >> n;
    // memoizaion
    d[0] = 1;
    d[2] = 3;
    // d[4] = d[2] * 3 + 2(d[4] 고유 모양 + d[4] 고유 모양 뒤집은거)
    // ㅡㅡ
    // |=|
    // d[6] = d[4] * 3 + {2(d[4] 고유 모양) * 3(case) + 2(d[6] 고유 모양)};
    // ㅡㅡㅡ
    // |==|
    for (int i = 3; i <= n; i++) {
        d[i] += d[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            d[i] += d[j] * 2;
        }
    }
    // result
    cout << d[n];
}