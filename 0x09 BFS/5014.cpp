#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    int board[F + 1];
    fill(board, board + F + 1, -1);

    queue<int> Q;
    Q.push(S);
    board[S] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (auto ny : {cur + U, cur - D}) {
            if (ny < 1 || ny > F) continue;
            if (board[ny] != -1) continue;

            board[ny] = board[cur] + 1;
            Q.push(ny);
        }
    }

    if (board[G] == -1)
        cout << "use the stairs";
    else
        cout << board[G];
}