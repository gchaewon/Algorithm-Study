#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> prior;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return prior[a.second] < prior[b.second];
    }
    return a.first > b.first;
}
int main() {
    int N, C;
    cin >> N >> C;
    map<int, int> m;
    vector<pair<int, int>> sorted_m;

    vector<int> v;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);

        if (m.find(temp) != m.end()) {
            m[temp]++;
        } else {
            m.insert({temp, 1});
            prior.insert({temp, count++});
        }
    }

    for (auto d : m) {
        sorted_m.push_back({d.second, d.first});
    }

    sort(sorted_m.begin(), sorted_m.end(), cmp);

    for (auto s : sorted_m) {
        for (int i = 0; i < s.first; i++) {
            cout << s.second << " ";
        }
    }
    return 0;
}