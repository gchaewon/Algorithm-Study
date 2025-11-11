#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        string word;
        string answer = "";
        cin >> word;
        int cnt = 0;

        do {
            answer = word;
            if (++cnt == 2) {
                break;
            }
        } while (next_permutation(word.begin(), word.end()));

        cout << answer << "\n";
    }
    return 0;
}