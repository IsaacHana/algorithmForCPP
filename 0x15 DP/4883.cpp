#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 0;
    while (true) {
        cin >> N;
        k++;
        if (N == 0) break;

        int board[N][3];
        int d[N][3];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
            }
        }

        d[0][0] = 1001;
        d[0][1] = board[0][1];
        d[0][2] = board[0][1] + board[0][2];

        for (int i = 1; i < N; i++) {
            d[i][0] = board[i][0] + min(d[i - 1][0], d[i - 1][1]);
            d[i][1] = board[i][1] + min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
            d[i][2] = board[i][2] + min({d[i - 1][1], d[i - 1][2], d[i][1]});
        }

        cout << k << ". " << d[N - 1][1] << '\n';
    }
}