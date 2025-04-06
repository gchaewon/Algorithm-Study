#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
int num[12];
set<vector<int>> ans;
vector<int> arr;

void backTracking(int cnt) {
    if (cnt == m) {
        ans.insert(arr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (num[i] < arr[cnt - 1]) {
            continue;
        }
        arr.push_back(num[i]);
        backTracking(cnt + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        arr.clear();
        arr.push_back(num[i]);
        backTracking(1);
    }

    for (auto a : ans) {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}