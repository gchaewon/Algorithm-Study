#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    unordered_set<string> memo;
    string word, post;

    for (int i = 0; i < n; i++) {
        cin >> word;
        memo.insert(word);
    }

    for (int i = 0; i < m; i++) {
        cin >> post;
        istringstream ss(post);

        while (getline(ss, word, ',')) {
            memo.erase(word);
        }
        cout << memo.size() << "\n";
    }
    return 0;
}