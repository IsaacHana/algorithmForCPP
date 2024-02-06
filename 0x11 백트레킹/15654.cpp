#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[9];
int arr[9];
int vis[9];

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            arr[depth] = board[i];
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
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    sort(board, board + N);
    backTracking(0);
}