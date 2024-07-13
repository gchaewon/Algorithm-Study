#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> array(n, 0);
    vector<int> sub_array(n, 1);
    set<vector<int>> answer;

    for (int i = 0; i < m; i++) {
        sub_array[i] = 0;
    }

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    do {
        // 숫자 뽑기
        vector<int> combi;
        for (int i = 0; i < n; i++) {
            if (sub_array[i] == 0) {
                combi.push_back(array[i]);
            }
        }
        // 뽑은 숫자로 순열
        do {
            vector<int> seq;
            for (int i = 0; i < combi.size(); i++) {
                seq.push_back(combi[i]);
            }
            answer.insert(seq);
        } while (next_permutation(combi.begin(), combi.end()));
    } while (next_permutation(sub_array.begin(), sub_array.end()));

    // 출력
    for (auto a : answer) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}