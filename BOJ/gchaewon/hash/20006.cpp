#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct room {
    int level;
    map<string, int> player;
};

int main() {
    int p, m;
    vector<room> rooms;
    cin >> p >> m;

    for (int i = 0; i < p; i++) {
        int l;
        string n;
        bool flag = false;
        cin >> l >> n;

        for (auto &r : rooms) {
            if (r.player.size() >= m) {
                continue;
            }
            int diff = abs(r.level - l);
            if (diff <= 10) {
                r.player.insert({n, l});
                flag = true;
                break;
            }
        }
        if (!flag) {
            rooms.push_back({l, {{n, l}}});
        }
    }

    for (auto r : rooms) {
        if (r.player.size() == m) {
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }
        for (auto player : r.player) {
            cout << player.second << " " << player.first << "\n";
        }
    }

    return 0;
}