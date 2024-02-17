#include <bits/stdc++.h>
using namespace std;

int N, M;

int num[10];
int arr[10];

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = start; i < N; i++) {
        if (tmp == num[i]) continue;
        arr[depth] = num[i];
        tmp = arr[depth];
        dfs(depth + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);
    dfs(0, 0);
}