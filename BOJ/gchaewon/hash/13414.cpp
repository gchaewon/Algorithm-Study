#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K, L;
    int count = 0;
    unordered_map<string, int> m;
    map<int, string> ans;

    cin >> K >> L;

    while (L--) {
        string temp;
        cin >> temp;
        if (m.find(temp) != m.end()) {
            m[temp] = count++;
            continue;
        }
        m.insert({temp, count++});
    }

    for (auto i : m) {
        ans.insert({i.second, i.first});
    }

    count = 0;
    for (auto i : ans) {
        if (count >= K) {
            break;
        }
        cout << i.second << "\n";
        count++;
    }

    return 0;
}