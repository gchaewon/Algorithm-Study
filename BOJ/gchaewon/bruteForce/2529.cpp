#include <bits/stdc++.h>

using namespace std;
int k;
string ans_max = "0";
string ans_min = "9999999999";
vector<char> v(10, 0);

void check(string num) {
    bool flag = true;
    for (int i = 0; i < k; i++) {
        if (!flag) {
            return;
        }
        switch (v[i]) {
        case '<':
            if (num[i] >= num[i + 1]) {
                flag = false;
            }
            break;
        case '>':
            if (num[i] <= num[i + 1]) {
                flag = false;
            }
            break;
        }
    }

    if (flag) {
        ans_max = max(ans_max, num);
        ans_min = min(ans_min, num);
    }
}

int main() {
    cin >> k;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    vector<int> sub_arr(arr.size(), 1);
    for (int i = 0; i < k + 1; i++) {
        sub_arr[i] = 0;
    }

    do {
        string temp;
        for (int i = 0; i < arr.size(); i++) {
            if (sub_arr[i] == 0) {
                temp += to_string(arr[i]);
            }
        }

        do {
            string temp2;
            for (int i = 0; i < temp.size(); i++) {
                temp2.push_back(temp[i]);
            }

            check(temp2);
        } while (next_permutation(temp.begin(), temp.end()));

    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans_max << "\n" << ans_min;

    return 0;
}