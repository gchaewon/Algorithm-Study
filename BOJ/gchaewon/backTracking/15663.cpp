#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<int> nums, arr;
set<vector<int>> arrs;
int include[12];

void dfs(int cnt) {
    if (cnt == m) {
        arrs.insert(arr);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (include[i]) {
            continue;
        }
        include[i] = 1;
        arr.push_back(nums[i]);

        dfs(cnt + 1);

        include[i] = 0;
        arr.pop_back();
    }
}
int main() {
    int num;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    dfs(0);

    for (vector<int> a : arrs) {
        for (int i : a) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}