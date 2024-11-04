#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int flag = 0;
    vector<int> count(26, 0);
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        count[str[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] >= 5) {
            cout << char(i + 'a');
            if (!flag) {
                flag = 1;
            }
        }
    }
    if (!flag) {
        cout << "PREDAJA";
    }
    return 0;
}