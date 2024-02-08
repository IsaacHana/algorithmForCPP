#include <bits/stdc++.h>
using namespace std;

int N, M;

int numbers[9];
int arr[9];

void backTracking(int depth, int start) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) cout << numbers[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int lastIndex = -1;
    for (int i = start; i < N; i++) {
        if (numbers[lastIndex] == numbers[i]) continue;
        arr[depth] = i;
        lastIndex = arr[depth];
        backTracking(depth + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + N);
    backTracking(0, 0);
}