#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<string> words;

void findWords(string word) {
    set<char> s;
    for (auto w : word) {
        s.insert(w);
        if (s.size() > k) { // 단어 구성 알파벳 개수가 k개 이상이면 제외
            return;
        }
    }
    words.push_back(word);
}

int findAns(set<char> s) {
    int cnt = 0;          // 읽을 수 있는 단어 개수 저장
    vector<int> a(26, 0); // 알파벳 포함 여부 저장

    // 가르친 글자 저장
    for (auto i : s) {
        a[i - 'a'] = 1;
    }
    for (auto word : words) {
        bool is_valid = true;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!a[idx]) { // 가르친 글자 중에 없는 경우
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> k;
    vector<char> alpha;
    int ans = 0;

    // 알파벳 저장
    for (int i = 0; i < 26; i++) {
        char a = (char('a' + i));
        // a, n, t, c, i 제외
        if (a == 'a' || a == 'n' || a == 't' || a == 'c' || a == 'i') {
            continue;
        }
        alpha.push_back(a);
    }

    // 알파벳 구성이 K개 이하인 단어만 추가
    while (n--) {
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        findWords(word);
    }

    // 가능한 단어가 없다면 조기 종료
    if (words.size() == 0) {
        cout << 0;
        return 0;
    }

    // a, c, i, n, t 포함 K개 글자 고르기
    vector<int> sub_arr(21, 1);
    for (int i = 0; i < k - 5; i++) {
        sub_arr[i] = 0;
    }
    do {
        set<char> s = {'a', 'c', 'i', 'n', 't'};
        for (int i = 0; i < alpha.size(); i++) {
            if (sub_arr[i] == 0) {
                s.insert(alpha[i]);
            }
        }
        // 글자 조합으로 읽을 수 있는 단어 수 갱신
        ans = max(ans, findAns(s));
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;

    return 0;
}