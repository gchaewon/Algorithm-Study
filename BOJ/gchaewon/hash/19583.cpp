#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    string S, E, Q, time, name;
    map<string, vector<string>> log;
    int ans = 0;

    cin >> S >> E >> Q;

    while (cin >> time) {
        cin >> name;
        // 입장
        if (time <= S) {
            if (log.find(name) == log.end()) {
                log.insert({name, {time}});
            }
        }
        // 퇴장
        if (time >= E && time <= Q) {
            if (log.find(name) != log.end() && log[name].size() != 0) {
                log[name].pop_back();
            }
        }
    }

    for (auto l : log) {
        if (l.second.size() == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}