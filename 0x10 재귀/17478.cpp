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
    cout << "\"����Լ��� ������?\"\n";
}

void print_recursive_answer(int depth) {
    make_under_bar(depth);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    make_under_bar(depth);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    make_under_bar(depth);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
}

void print_answer(int depth) {
    make_under_bar(depth);
    cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
}

void print_answered(int depth) {
    make_under_bar(depth);
    cout << "��� �亯�Ͽ���.\n";
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
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    recursion(0);
}