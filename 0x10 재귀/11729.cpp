#include <bits/stdc++.h>
using namespace std;

void recursion(int K, int start, int target) {
    // base case
    if (K == 1) {
        cout << start << ' ' << target << '\n';
        return;
    }
    int tmp = 6 - start - target;
    recursion(K - 1, start, tmp);
    cout << start << ' ' << target << '\n';
    recursion(K - 1, tmp, target);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    cout << (1 << K) - 1 << '\n';
    recursion(K, 1, 3);
}