#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool vis[10];

void dfs(int depth) {
    // base
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        arr[depth] = i;
        vis[i] = true;
        dfs(depth + 1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dfs(0);
}