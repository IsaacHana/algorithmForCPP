#include <bits/stdc++.h>
using namespace std;

int dist[1'000'001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X;
    cin >> X;
    for (int i = 2; i <= X; i++) {
        dist[i] = dist[i - 1] + 1;
        if (i % 3 == 0) {
            dist[i] = min(dist[i], dist[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dist[i] = min(dist[i], dist[i / 2] + 1);
        }
    }

    cout << dist[X] << '\n';
}