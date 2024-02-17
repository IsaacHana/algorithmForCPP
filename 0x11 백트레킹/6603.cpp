#include <bits/stdc++.h>
using namespace std;

const int MIN_NUM = 1;
const int MAX_NUM = 49;
const int M = 6;

int N;
int num[51];
int arr[M];

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        arr[depth] = num[i];
        dfs(depth + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) cin >> num[i];
        dfs(0, 0);
        cout << '\n';
    }
}