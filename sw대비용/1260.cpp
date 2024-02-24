#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge(1001);
bool vis[1001];

void DFS(int V) {
    if (vis[V]) {
        return;
    }

    vis[V] = true;
    cout << V << ' ';

    for (auto negighbor : edge[V]) {
        DFS(negighbor);
    }
}

void BFS(int V) {
    queue<int> q;
    q.push(V);
    vis[V] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto neighbor : edge[cur]) {
            if (vis[neighbor]) continue;
            vis[neighbor] = true;
            q.push(neighbor);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, V;
    cin >> N >> M >> V;
    int a, b;
    while (M--) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 0; i < edge.size(); i++) {
        sort(edge[i].begin(), edge[i].end());
    }
    DFS(V);
    cout << '\n';
    fill(vis, vis + 1001, 0);
    BFS(V);
}