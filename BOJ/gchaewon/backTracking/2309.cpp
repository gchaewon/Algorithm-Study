// 조합 정렬 문제
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n = 9;
    int m = 7;
    vector<int> array(n, 0);
    vector<int> sub_array(n, 1);
    set<vector<int>> comb;

    for (int i = 0; i < m; i++) {
        sub_array[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    do {
        vector<int> temp;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sub_array[i] == 0) {
                temp.push_back(array[i]);
                sum += array[i];
            }
        }
        if (sum == 100) {
            for (auto i : temp) {
                cout << i << "\n";
            }
            break;
        }

    } while (next_permutation(sub_array.begin(), sub_array.end()));

    return 0;
}