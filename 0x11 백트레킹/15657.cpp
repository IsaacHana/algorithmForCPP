#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[9];
int arr[9];

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << board[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int start = 0;
    if (depth != 0) start = arr[depth - 1];
    for (int i = start; i < N; i++) {
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