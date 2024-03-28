#include <bits/stdc++.h>
using namespace std;

int A[101][101];
int r_size = 3;
int c_size = 3;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void R_sort() {
    int mx_r_size = 0;
    for (int i = 0; i < c_size; i++) {
        map<int, int> map;

        for (int j = 0; j < r_size; j++) {
            if (A[i][j] == 0) continue;
            if (map[A[i][j]])
                map[A[i][j]] += 1;
            else
                map[A[i][j]] = 1;
        }

        if (map.empty()) break;

        // cout << "=======map========\n";
        // for (auto m : map) {
        //     cout << m.first << ' ' << m.second << '\n';
        // }

        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), comp);

        mx_r_size = max(mx_r_size, 2 * (int)vec.size());

        // cout << "=======vec=======\n";

        fill(A[i], A[i] + 100, 0);

        for (int j = 0; j < vec.size(); j++) {
            auto v = vec[j];
            // cout << v.first << ' ' << v.second << '\n';
            A[i][2 * j] = v.first;
            A[i][2 * j + 1] = v.second;
        }
    }

    r_size = mx_r_size;
}

void C_sort() {
    int mx_c_size = 0;

    for (int i = 0; i < r_size; i++) {
        map<int, int> map;

        for (int j = 0; j < c_size; j++) {
            if (A[j][i] == 0) continue;
            ;
            if (map[A[j][i]])
                map[A[j][i]] += 1;
            else
                map[A[j][i]] = 1;
        }

        if (map.empty()) break;

        // cout << "=======map========\n";
        // for (auto m : map) {
        //     cout << m.first << ' ' << m.second << '\n';
        // }

        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), comp);

        mx_c_size = max(mx_c_size, 2 * (int)vec.size());

        // cout << "=======vec=======\n";

        for (int j = 0; j < r_size; j++) {
            A[j][i] = 0;
        }

        for (int j = 0; j < vec.size(); j++) {
            auto v = vec[j];
            // cout << v.first << ' ' << v.second << '\n';
            A[2 * j][i] = v.first;
            A[2 * j + 1][i] = v.second;
        }
    }

    c_size = mx_c_size;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    int cnt = 0;

    while (A[r - 1][c - 1] != k && cnt <= 100) {
        cnt++;

        if (c_size >= r_size) {
            R_sort();
        } else {
            C_sort();
        }

        // cout << "=======" << cnt << "=======\n";
        // cout << r_size << " " << c_size << '\n';
        // for (int i = 0; i < c_size; i++) {
        //     for (int j = 0; j < r_size; j++) {
        //         cout << A[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    if (cnt > 100)
        cout << -1 << '\n';
    else
        cout << cnt << '\n';
}