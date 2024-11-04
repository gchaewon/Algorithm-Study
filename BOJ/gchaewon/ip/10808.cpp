// 알파벳 개수 카운팅
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<int> v(26, 0);
    cin >> str;

    for (auto i : str) {
        v[i - 'a']++;
    }
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}