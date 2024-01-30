#include <bits/stdc++.h>
using namespace std;

int N;

void make_under_bar(int depth) {
    for (int i = 0; i < depth * 4; i++) {
        cout << "_";
    }
}

void print_question(int depth) {
    make_under_bar(depth);
    cout << "\"재귀함수가 뭔가요?\"\n";
}

void print_recursive_answer(int depth) {
    make_under_bar(depth);
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    make_under_bar(depth);
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    make_under_bar(depth);
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
}

void print_answer(int depth) {
    make_under_bar(depth);
    cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
}

void print_answered(int depth) {
    make_under_bar(depth);
    cout << "라고 답변하였지.\n";
}

void recursion(int depth) {
    print_question(depth);
    // base case
    if (N == depth) {
        print_answer(depth);
    } else {
        print_recursive_answer(depth);
        recursion(depth + 1);
    }
    print_answered(depth);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    recursion(0);
}