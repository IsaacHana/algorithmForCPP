#include <bits/stdc++.h>
using namespace std;

struct Egg {
    int dur;
    int wei;

    Egg(int d, int w) : dur(d), wei(w){};
};

int N;
vector<Egg> egg;
int ans = 0;

bool vis[10];

void dfs(int depth, int cnt) {
    if (ans >= cnt + 2 * (N - depth)) {
        return;
    }

    if (depth == N) {
        ans = max(ans, cnt);
        return;
    }

    if (egg[depth].dur <= 0) {
        dfs(depth + 1, cnt);
        return;
    }

    bool crush = false;

    for (int i = 0; i < N; i++) {
        if (depth == i) continue;
        if (egg[i].dur <= 0) continue;

        crush = true;

        egg[depth].dur -= egg[i].wei;
        egg[i].dur -= egg[depth].wei;
        dfs(depth + 1, cnt + (egg[depth].dur <= 0) + (egg[i].dur <= 0));
        egg[depth].dur += egg[i].wei;
        egg[i].dur += egg[depth].wei;
    }

    if (crush == false) dfs(depth + 1, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int dur, wei;
    for (int i = 0; i < N; i++) {
        cin >> dur >> wei;
        Egg cur_egg(dur, wei);
        egg.push_back(cur_egg);
    }

    dfs(0, 0);  // depth, count

    cout << ans << '\n';
}