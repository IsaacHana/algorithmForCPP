#include <bits/stdc++.h>
using namespace std;

long long POW(long long A, long long B, long long C) {
    if (B == 1) return A % C;
    long long tmp = POW(A, B / 2, C);
    tmp = tmp * tmp % C;
    if (B % 2 == 0) return tmp;
    return tmp * A % C;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long A, B, C;
    cin >> A >> B >> C;
    cout << POW(A, B, C);
}