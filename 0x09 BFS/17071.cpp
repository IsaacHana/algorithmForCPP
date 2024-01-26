#include <bits/stdc++.h>
using namespace std;

const int MX = 500'000;
int dist[2][MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 2; i++) fill(dist[i], dist[i] + MX + 1, -1);

    queue<pair<int, int>> NQ;
    NQ.push({0, N});
    dist[0][N] = 0;

    while (!NQ.empty()) {
        int curTime, curPos;
        tie(curTime, curPos) = NQ.front();
        NQ.pop();
        int nxtTime = curTime + 1;
        for (int nxtPos : {curPos - 1, curPos + 1, curPos * 2}) {
            if (nxtPos < 0 || nxtPos > MX) continue;
            if (dist[nxtTime % 2][nxtPos] != -1) continue;

            dist[nxtTime % 2][nxtPos] = nxtTime;
            NQ.push({nxtTime, nxtPos});
        }
    }

    queue<pair<int, int>> KQ;
    KQ.push({0, K});
    while (!KQ.empty()) {
        int curTime, curPos;
        tie(curTime, curPos) = KQ.front();
        KQ.pop();

        if (dist[curTime % 2][curPos] <= curTime) {
            cout << curTime;
            return 0;
        }

        int nxtTime = curTime + 1;
        int nxtPos = curPos + nxtTime;
        if (nxtPos > MX) continue;
        KQ.push({nxtTime, nxtPos});
    }

    cout << -1;
}