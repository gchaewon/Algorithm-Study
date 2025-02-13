#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();

    set<string> sub_set;

    for (int i = 0; i < len; i++) {
        string temp = "";
        for (int j = i; j < len; j++) {
            temp += s[j];
            for (int k = j; k <= j; k++) {
                sub_set.insert(temp);
            }
        }
    }

    cout << sub_set.size();
    return 0;
}