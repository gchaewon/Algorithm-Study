#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int include[12];
vector<int> nums, arr;

void dfs(int cnt) {
    if (cnt == m) {
        for (int a : arr) {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < nums[i]; i++) {
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