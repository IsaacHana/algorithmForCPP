#include <bits/stdc++.h>
using namespace std;

bool vis1[15];
bool vis2[30];
bool vis3[30];
int N;
int cnt = 0;

void backTracking(int depth) {
    if (depth == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis1[i] || vis2[i + depth] || vis3[depth - i + N - 1]) continue;
        vis1[i] = true;
        vis2[i + depth] = true;
        vis3[depth - i + N - 1] = true;
        backTracking(depth + 1);

        vis1[i] = false;
        vis2[i + depth] = false;
        vis3[depth - i + N - 1] = false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    backTracking(0);
    cout << cnt;
}