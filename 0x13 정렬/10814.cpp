#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    pair<int, string> x[N];

    for (auto& s : x) cin >> s.first >> s.second;
    stable_sort(x, x + N, [&](pair<int, string> a, pair<int, string> b) { return a.first < b.first; });

    for (auto p : x) cout << p.first << ' ' << p.second << '\n';
}