#include <deque>
#include <iostream>
#include <vector>

using namespace std;

string ac_function(deque<int> &q, string p) {
    bool is_reversed = false;
    string output = "[";
    for (auto option : p) {
        switch (option) {
        case 'R':
            is_reversed = !is_reversed;
            break;
        case 'D':
            if (q.size() == 0) {
                return "error";
            }
            if (is_reversed) {
                q.pop_back();
                break;
            }
            q.pop_front();
        }
    }

    if (is_reversed) {
        while (!q.empty()) {
            output += to_string(q.back());
            q.pop_back();
            if (q.size() != 0) {
                output += ',';
            }
        }
        output += ']';
        return output;
    }

    while (!q.empty()) {
        output += to_string(q.front());
        q.pop_front();
        if (q.size() != 0) {
            output += ',';
        }
    }
    output += ']';
    return output;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        string p;
        string input;
        deque<int> q;
        int n;

        cin >> p;
        cin >> n;
        cin >> input;

        for (int i = 1; i < input.length() - 1; i++) {
            string temp = "";
            while (input[i] != ',' && i < input.length() - 1) {
                temp += input[i];
                i++;
            }
            q.push_back(stoi(temp));
        }
        cout << ac_function(q, p) << "\n";
    }
    return 0;
}