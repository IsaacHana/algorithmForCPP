#include <bits/stdc++.h>
using namespace std;

int N, S;
int num[20];
int cnt = 0;
void dfs(int depth, int total) {
    // base
    if (depth == N) {
        if (total == S) cnt++;
        return;
    }

    dfs(depth + 1, total);  // ¼±ÅÃ X
    dfs(depth + 1, total + num[depth]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    dfs(0, 0);
    if (S == 0) cnt--;
    cout << cnt;
}