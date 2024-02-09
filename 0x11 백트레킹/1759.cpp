#include <bits/stdc++.h>
using namespace std;

char ch[16];
char arr[16];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
int L, C;

bool valid() {
    int v_cnt = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] == vowel[j]) {
                v_cnt++;
            }
        }
    }

    return (L - v_cnt) >= 2 && v_cnt >= 1;  // 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다
}
void backTracking(int depth, int start) {
    // base case
    if (L == depth) {
        if (!valid()) return;

        for (int i = 0; i < L; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < C; i++) {
        arr[depth] = ch[i];
        backTracking(depth + 1, i + 1);
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
    backTracking(0, 0);
}