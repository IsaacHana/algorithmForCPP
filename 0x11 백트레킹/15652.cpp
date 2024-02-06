#include <bits/stdc++.h>
using namespace std;

int arr[9];
int vis[9];
int N, M;

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int start = 1;
    if (depth != 0) start = arr[depth - 1];

    for (int i = start; i <= N; i++) {
        arr[depth] = i;
        backTracking(depth + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    backTracking(0);
}