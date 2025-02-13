#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        int temp = 1;
        map<string, int> m;
        cin >> n;

        while (n--) {
            string category, cloth;
            cin >> cloth >> category;

            // 처음 등록하는 경우
            if (m.find(category) == m.end()) {
                m.insert({category, 1});
            } else {
                m[category]++;
            }
        }

        for (auto i : m) {
            temp *= (i.second + 1);
        }
        temp -= 1;
        cout << temp << "\n";
    }

    return 0;
}