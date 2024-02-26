#include <bits/stdc++.h>
using namespace std;

bool vis[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int node_cnt, edge_cnt;

    cin >> node_cnt >> edge_cnt;
    vector<vector<int>> edge(node_cnt + 1);

    int a, b;
    for (int i = 1; i <= edge_cnt; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    int worm_cnt = -1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        worm_cnt++;
        for (auto neighbor : edge[cur]) {
            if (vis[neighbor]) continue;

            vis[neighbor] = true;
            q.push(neighbor);
        }
    }

    // for (int i = 0; i <= node_cnt; i++) {
    //     cout << vis[i] << ' ';
    // }

    cout << worm_cnt << '\n';
}