#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m, num, option;
    string team, member, quiz;
    cin >> n >> m;

    map<string, set<string>> groups;
    map<string, string> members;

    while (n--) {
        cin >> team >> num;
        for (int i = 0; i < num; i++) {
            cin >> member;
            groups[team].insert(member);
            members[member] = team;
        }
    }
    while (m--) {
        cin >> quiz >> option;
        if (option) {
            cout << members[quiz] << "\n";
        } else {
            for (auto g : groups[quiz]) {
                cout << g << "\n";
            }
        }
    }

    return 0;
}