#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> arr;

void dfs(int cnt) {
    if (cnt == m) {
        for (int a : arr) {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
        dfs(cnt + 1);
        arr.pop_back();
    }
}
int main() {
    cin >> n >> m;

    dfs(0);

    return 0;
}