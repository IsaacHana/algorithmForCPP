#include <bits/stdc++.h>
using namespace std;

int arr[20];

int N, S;
int cnt = 0;

void sum_permutaion(int depth, int total) {
    if (N == depth) {
        if (S == total) cnt += 1;
        return;
    }

    sum_permutaion(depth + 1, total);
    sum_permutaion(depth + 1, total + arr[depth]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sum_permutaion(0, 0);
    if (S == 0) cnt--;
    cout << cnt;
}