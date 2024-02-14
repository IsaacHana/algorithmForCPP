// ZOAC 4
// https://www.acmicpc.net/problem/23971

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double H, W, N, M;

    cin >> H >> W >> N >> M;

    cout << (long long)ceil(H / (N + 1)) * (long long)ceil(W / (M + 1));
}