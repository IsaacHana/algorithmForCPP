#include <bits/stdc++.h>
using namespace std;

const int MIN_NUM = 1;
const int MAX_NUM = 49;
const int CNT = 6;

int k;
int num[14];
int arr[14];

void backTracking(int depth, int start) {
    // base case
    if (depth == CNT) {
        for (int i = 0; i < CNT; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < k; i++) {
        arr[depth] = num[i];
        backTracking(depth + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> num[i];
        }

        backTracking(0, 0);
        cout << '\n';
    }
}