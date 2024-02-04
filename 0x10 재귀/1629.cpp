#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll recursion(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = recursion(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;
    cout << recursion(A, B, C);
}