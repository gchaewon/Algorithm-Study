#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_LEN = 10004;

vector<vector<int>> alpha(26); // alpha[0] 알파벳 a의 위치 {1, 3, 5}
int getShortLen(int k) {
    int min_length = MAX_LEN;

    for (int i = 0; i < 26; i++) {
        if (!alpha[i].size()) {
            continue;
        }
        // k개 포함하는 경우 끝 - 시작 인덱스 + 1로 길이 구하기
        for (int j = 0; j + k - 1 < alpha[i].size(); j++) {
            int length = alpha[i][j + k - 1] - alpha[i][j] + 1;
            min_length = min(min_length, length);
        }
    }
    return min_length;
}

int getLongLen(int k) {
    int max_length = 0;

    for (int i = 0; i < 26; i++) {
        if (!alpha[i].size()) {
            continue;
        }
        // k개 포함하는 경우 끝 - 시작 인덱스 + 1로 길이 구하기
        for (int j = 0; j + k - 1 < alpha[i].size(); j++) {
            int length = alpha[i][j + k - 1] - alpha[i][j] + 1;
            max_length = max(max_length, length);
        }
    }
    return max_length;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string w;
        int k;
        cin >> w >> k;

        // 초기화
        for (int i = 0; i < 26; i++) {
            alpha[i].clear();
        }
        // 알파벳 위치 저장
        for (int i = 0; i < w.size(); i++) {
            alpha[w[i] - 'a'].push_back(i);
        }

        int short_length = getShortLen(k);
        int long_length = getLongLen(k);

        if (short_length == MAX_LEN || long_length == 0) {
            cout << -1 << "\n";
            continue;
        }

        cout << short_length << " " << long_length << "\n";
    }
    return 0;
}