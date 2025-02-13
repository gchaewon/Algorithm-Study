#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int N, M, option;
    map<string, set<string>> m;
    map<string, string> members;
    string team, name;
    cin >> N >> M;

    while (N--) {
        int num;
        cin >> team >> num;
        m.insert({team, {}});
        while (num--) {
            cin >> name;
            m[team].insert(name);
            members.insert({name, team});
        }
    }

    while (M--) {
        cin >> name >> option;
        if (option) {
            string team = members[name];
            cout << team << "\n";
        } else {
            for (auto t : m[name]) {
                cout << t << "\n";
            }
        }
    }
    return 0;
}