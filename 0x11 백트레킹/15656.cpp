#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[8];
int arr[8];
int vis[8];

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << board[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        arr[depth] = i;
        backTracking(depth + 1);
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