#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int ans = 0;
    cin >> n >> m;

    vector<string> words;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }

    // 문자열 정렬
    sort(words.begin(), words.end());

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        int left = 0;
        int right = words.size();

        while (left <= right) {
            int mid = (left + right) / 2;

            // 접두사가 되는 단어를 찾은 경우
            if (words[mid].find(str) == 0) {
                ans++;
                break;
            }
            // 못찾은 경우 탐색 범위 조정
            string substr = words[mid].substr(0, str.size());
            if (substr < str) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    cout << ans;

    return 0;
}