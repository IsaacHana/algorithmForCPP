#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int r, int c) {
    // base case
    if (n == 0) return 0;
    int half = 1 << (n - 1);
    if (r < half && c < half) return recursion(n - 1, r, c);                            // 2��и�
    if (r < half && c >= half) return half * half + recursion(n - 1, r, c - half);      // 1��и�
    if (r >= half && c < half) return 2 * half * half + recursion(n - 1, r - half, c);  // 3��и�
    return 3 * half * half + recursion(n - 1, r - half, c - half);                      // 4��и�
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << recursion(N, r, c);
}