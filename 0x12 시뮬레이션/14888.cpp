#include <bits/stdc++.h>
using namespace std;

int N;
int num[102];
int oper[4];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;

void dfs(int depth, int ans) {
    if (depth == N) {
        mx = max(mx, ans);
        mn = min(mn, ans);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!oper[i]) continue;
        oper[i]--;
        if (i == 0)
            dfs(depth + 1, ans + num[depth]);
        else if (i == 1)
            dfs(depth + 1, ans - num[depth]);
        else if (i == 2)
            dfs(depth + 1, ans * num[depth]);
        else if (i == 3)
            if (ans < 0) {
                ans *= -1;
                int tmp = ans / num[depth];
                tmp *= -1;
                dfs(depth + 1, tmp);
            } else {
                dfs(depth + 1, ans / num[depth]);
            }
        oper[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    dfs(1, num[0]);

    cout << mx << '\n';
    cout << mn << '\n';
}