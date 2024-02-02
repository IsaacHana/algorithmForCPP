#include <bits/stdc++.h>
using namespace std;

pair<int, int> hilbert(int n, int m) {
    // base case
    if (n == 2) {
        if (m == 1) {
            return {1, 1};
        } else if (m == 2) {
            return {1, 2};
        } else if (m == 3) {
            return {2, 2};
        } else if (m == 4) {
            return {2, 1};
        }
    }

    int half = n / 2;
    int square = half * half;
    pair<int, int> cur;
    if (m <= square) {
        cur = hilbert(half, m);
        // 오른쪽으로 돌리기
        return {cur.second, cur.first};
    } else if (m <= 2 * square) {
        cur = hilbert(half, m - square);
        return {cur.first, cur.second + half};
    } else if (m <= 3 * square) {
        cur = hilbert(half, m - 2 * square);
        return {cur.first + half, cur.second + half};
    } else if (m <= 4 * square) {
        cur = hilbert(half, m - 3 * square);
        // 왼쪽으로 돌리기
        return {2 * half - cur.second + 1, half - cur.first + 1};
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> ans = hilbert(n, m);
    cout << ans.first << ' ' << ans.second;
}