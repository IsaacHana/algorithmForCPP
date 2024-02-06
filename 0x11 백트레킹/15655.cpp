#include <bits/stdc++.h>
using namespace std;

int N, M;
int numbers[9];
int arr[9];
bool vis[9];

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << numbers[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 0;
    if (depth != 0) start = arr[depth - 1] + 1;
    for (int i = start; i < N; i++) {
        if (!vis[i]) {
            arr[depth] = i;
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
        cin >> numbers[i];
    }
    sort(numbers, numbers + N);
    backTracking(0);
}