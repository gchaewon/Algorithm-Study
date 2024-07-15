#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void lotto(vector<int> s, int k) {
    vector<int> sub_array(k, 1);

    for (int i = 0; i < 6; i++) {
        sub_array[i] = 0;
    }

    do {
        for (int i = 0; i < k; i++) {
            if (sub_array[i] == 0) {
                cout << s[i] << " ";
            }
        }
        cout << "\n";
    } while (next_permutation(sub_array.begin(), sub_array.end()));
    cout << "\n";
}
int main() {
    while (true) {
        string input;
        vector<int> s;
        getline(cin, input);

        if (input == "0") {
            break;
        }

        stringstream sinput(input);
        string num;
        while (sinput >> num) {
            s.push_back(stoi(num));
        }
        int k = s[0];
        s.erase(s.begin());
        lotto(s, k);
    }

    return 0;
}
