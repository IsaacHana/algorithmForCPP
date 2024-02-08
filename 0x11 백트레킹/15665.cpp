#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int numbers[8];
int arr[8];

void backTracking(int depth) {
    // base case
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (tmp == numbers[i]) continue;
        arr[depth] = numbers[i];
        tmp = arr[depth];
        backTracking(depth + 1);
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
    backTracking(0);
}