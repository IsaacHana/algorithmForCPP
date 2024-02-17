#include <bits/stdc++.h>
using namespace std;

int L, C;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
char ch[26];
char arr[26];

bool valid() {
    int v_cnt = 0;

    for (int i = 0; i < L; i++) {
        for (auto v : vowel) {
            if (arr[i] == v) v_cnt++;
        }
    }
    return v_cnt >= 1 && (L - v_cnt) >= 2;
}

void dfs(int depth, int start) {
    if (depth == L) {
        if (!valid()) return;

        for (int i = 0; i < L; i++) {
            cout << arr[i];
        }
        cout << '\n';

        return;
    }

    for (int i = start; i < C; i++) {
        arr[depth] = ch[i];
        dfs(depth + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> ch[i];
    }
    sort(ch, ch + C);
    dfs(0, 0);
}