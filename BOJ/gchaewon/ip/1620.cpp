#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string input;
    cin >> n >> m;
    map<string, int> map1;
    map<int, string> map2;

    for (int i = 1; i <= n; i++) {
        cin >> input;
        map1.insert({input, i});
        map2.insert({i, input});
    }

    while (m--) {
        cin >> input;
        if ((input[0] - 'A') >= 0) { // 이름 입력
            cout << map1[input] << "\n";
        } else { // 숫자 입력
            cout << map2[stoi(input)] << "\n";
        }
    }

    return 0;
}