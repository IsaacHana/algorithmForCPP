#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[100'002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + N);
    for (int i = 0; i < N; i++) {
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
}