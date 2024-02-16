#include <bits/stdc++.h>
using namespace std;

int N, M;

int arr[10];

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= N; i++) {
        arr[depth] = i;
        dfs(depth + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    dfs(0, 1);
}