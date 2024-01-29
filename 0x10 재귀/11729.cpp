#include <bits/stdc++.h>
using namespace std;

void recursion(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    recursion(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    recursion(6 - a - b, b, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    recursion(1, 3, n);
}