#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(vector<int>& v) {
    int idx = 0;
    int cnt = 1;

    while (idx < N - 1) {
        // ������ 1 �ʰ��� ��
        if (abs(v[idx + 1] - v[idx]) > 1) return 0;

        // �������� ������ �̵�
        if (v[idx] == v[idx + 1]) {
            idx++;
            cnt++;
        }
        // ������ ������
        else if (v[idx] < v[idx + 1]) {
            // ������ �κ��� L���� ������ ��
            if (cnt < L) return 0;
            cnt = 1;
            idx++;
        }
        // ������ ������
        else {
            // L��ŭ�� ���̰� ������ ��
            if (idx + L >= N) return 0;
            // 3 2 2 1 1 1
            for (int i = idx + 1; i < idx + L; i++) {
                if (v[i] != v[i + 1]) return 0;
            }
            idx += L;
            cnt = 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            v.push_back(board[i][j]);
        }
        ans += check(v);
    }

    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            v.push_back(board[j][i]);
        }
        ans += check(v);
    }


    cout << ans << '\n';
}