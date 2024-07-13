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
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    do {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (sub_array[i] == 0) {
                temp.push_back(array[i]);
            }
        }
        answer.insert(temp);
    } while (next_permutation(sub_array.begin(), sub_array.end()));

    for (auto i : answer) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}