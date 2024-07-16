#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, c;
    cin >> l >> c;

    vector<char> array(c, 0);
    vector<int> sub_array(c, 1);
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    set<string> ciphers;

    // 입력
    for (int i = 0; i < c; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < l; i++) {
        sub_array[i] = 0;
    }
    sort(array.begin(), array.end());

    do {
        // l개 문자 뽑아 순열
        string seq = "";
        int count = 0;
        for (int i = 0; i < c; i++) {
            if (sub_array[i] == 0) {
                seq.push_back(array[i]);
            }
        }
        // 암호가 조건을 만족하는지 모음 개수 count
        for (auto i : seq) {
            for (auto v : vowel) {
                if (i == v) {
                    count++;
                }
            }
        }
        // 자모음 갯수 조건 만족하면 출력
        if (count == 0 || (seq.length() - count <= 1)) {
            continue;
        } else {
            cout << seq << "\n";
        }
    } while (next_permutation(sub_array.begin(), sub_array.end()));

    return 0;
}