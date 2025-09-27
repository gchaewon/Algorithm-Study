#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
int nums[1004];
vector<int> arr;
set<vector<int>> arrs; // 중복 허용하지 않으므로 set

void backTracking(int cnt) {
    // m개 뽑으면 종료
    if (cnt == m) {
        arrs.insert(arr);
        return;
    }

    // 수 고르기
    for (int i = 0; i < n; i++) {
        // 추가
        arr.push_back(nums[i]);
        // 탐색
        backTracking(cnt + 1);
        // 원복
        arr.pop_back();
    }
}
int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    backTracking(0);

    for (vector<int> a : arrs) {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}