#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];
bool vis[9];

void backTracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            arr[depth] = i;

            vis[i] = true;
            backTracking(depth + 1);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backTracking(0);
}