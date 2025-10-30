#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> nums, arr;

void dfs(int cnt) {
    if (cnt == m) {
        for (int a : arr) {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for (int num : nums) {
        if (!arr.empty() && num <= arr.back()) {
            continue;
        }
        arr.push_back(num);
        dfs(cnt + 1);
        arr.pop_back();
    }
}
int main() {
    cin >> n >> m;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    dfs(0);

    return 0;
}