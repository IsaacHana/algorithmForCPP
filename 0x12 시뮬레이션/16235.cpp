#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[12][12];
int ground[12][12];

deque<int> trees[12][12];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring(int r, int c) {
    auto &t = trees[r][c];
    int idx = 0;
    // º½
    for (; idx < t.size(); idx++) {
        if (ground[r][c] < t[idx]) break;

        ground[r][c] -= t[idx];
        t[idx] += 1;
    }

    // ¿©¸§
    for (int i = idx; i < t.size(); i++) {
        ground[r][c] += t[i] / 2;
    }

    t.erase(t.begin() + idx, t.end());
}

void fall(int r, int c) {
    for (auto &t : trees[r][c]) {
        if (t % 5 != 0) continue;

        for (int dir = 0; dir < 8; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            trees[nr][nc].push_front(1);
        }
    }
    ground[r][c] += A[r][c];
}

// void winter(int r, int c) { ground[r][c] += A[r][c]; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }

    int r, c, age;
    while (M--) {
        cin >> r >> c >> age;
        trees[r][c].push_back(age);
    }

    while (K--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                spring(i, j);
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                fall(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += trees[i][j].size();
        }
    }

    cout << ans << '\n';
}