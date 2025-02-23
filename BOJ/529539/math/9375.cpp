#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, answer;
    string type, name;
    cin >> k;
    while (k--)
    {
        cin >> n;
        map<string, int> clothes;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> type;
            clothes[type]++;
        }
        answer = 1; // 초기화 필수
        for (map<string, int>::iterator it = clothes.begin(); it != clothes.end(); it++)
            answer *= (it->second + 1);
        cout << answer - 1 << "\n";
    }
}