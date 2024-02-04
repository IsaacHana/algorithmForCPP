#include <bits/stdc++.h>
using namespace std;

int recursion(int N, int x, int y) {
    // base case
    if (N == 0) return 0;
    int half = 1 << (N - 1);

    if (x < half && y < half) return recursion(N - 1, x, y);

    if (x < half && y >= half) return half * half + recursion(N - 1, x, y - half);

    if (x >= half && y < half) return 2 * half * half + recursion(N - 1, x - half, y);

    if (x >= half && y >= half) return 3 * half * half + recursion(N - 1, x - half, y - half);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    cout << recursion(N, r, c);
}