#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[100'002];

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + N);
    for (int i = 0; i < N; i++) {
        cout << p[i].second << ' ' << p[i].first << '\n';
    }
}