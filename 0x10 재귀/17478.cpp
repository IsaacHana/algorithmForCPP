#include <bits/stdc++.h>
using namespace std;

int N;
void recursion(int depth) {
    cout << string(depth * 4, '_') << "\"����Լ��� ������?\"\n";

    if (N == depth) {
        cout << string(depth * 4, '_') << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    } else {
        cout << string(depth * 4, '_') << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        cout << string(depth * 4, '_') << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        cout << string(depth * 4, '_') << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        recursion(depth + 1);
    }

    cout << string(depth * 4, '_') << "��� �亯�Ͽ���.\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursion(0);
}