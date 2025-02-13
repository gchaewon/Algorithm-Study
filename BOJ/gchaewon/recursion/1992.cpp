#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[65][65];

void recur(int x, int y, int size) {
    if (size == 1) {
        cout << arr[x][y];
        return;
    }
    int start = arr[x][y];
    bool flag = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != start) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << start;
    }

    else {
        cout << "(";
        recur(x, y, size / 2);
        recur(x, y + (size / 2), size / 2);
        recur(x + (size / 2), y, size / 2);
        recur(x + (size / 2), y + (size / 2), size / 2);
        cout << ")";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    recur(0, 0, n);
    return 0;
}