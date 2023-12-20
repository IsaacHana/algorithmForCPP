#include <bits/stdc++.h>
using namespace std;

list<char> keyLogger(string key)
{
    list<char> linkedList;
    auto cursor = linkedList.begin();
    for (auto c : key)
    {
        if (c == '-')
        {
            if (cursor != linkedList.begin())
            {
                cursor--;
                cursor = linkedList.erase(cursor);
            }
        }
        else if (c == '<')
        {
            if (cursor != linkedList.begin())
                cursor--;
        }
        else if (c == '>')
        {
            if (cursor != linkedList.end())
                cursor++;
        }
        else
        {
            linkedList.insert(cursor, c);
        }
    }

    return linkedList;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string key;
        cin >> key;

        for (auto c : keyLogger(key))
            cout << c;
        cout << '\n';
    }
}