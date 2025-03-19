#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> dic;

bool cmp(string &a, string &b) {
    if (dic[a] == dic[b]) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() > b.length();
    }
    return dic[a] > dic[b];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if (temp.size() < m) {
            continue;
        }
        if (dic[temp] == 0) {
            v.push_back(temp);
        }
        dic[temp] += 1;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}