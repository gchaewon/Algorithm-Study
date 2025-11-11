#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, answer = 1;
    set<string> s;
    string word;
    vector<string> words;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        s.insert(word);
    }

    for (auto i : s) {
        words.push_back(i);
    }

    for (int i = 0; i < words.size() - 1; i++) {
        string sub = words[i + 1].substr(0, words[i].size());
        if (words[i] != sub) {
            answer++;
        }
    }
    cout << answer;

    return 0;
}