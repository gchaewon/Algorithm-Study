#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int a[24][24];
int dice[7], temp[7];

void copyDice() {
    for (int i = 1; i <= 6; i++) {
        temp[i] = dice[i];
    }
}
void makeBottom(int idx) {
    if (a[x][y] == 0) {
        a[x][y] = temp[idx];
        dice[6] = temp[idx];
    } else {
        dice[6] = a[x][y];
        a[x][y] = 0;
    }
}

// 동
bool func1() {
    if (y + 1 >= m) {
        return false;
    }
    y += 1;
    copyDice();
    makeBottom(3);

    dice[1] = temp[4];
    dice[3] = temp[1];
    dice[4] = temp[6];

    return true;
}
// 서
bool func2() {
    if (y - 1 < 0) {
        return false;
    }
    y -= 1;
    copyDice();
    makeBottom(4);

    dice[1] = temp[3];
    dice[4] = temp[1];
    dice[3] = temp[6];

    return true;
}
// 북
bool func3() {
    if (x - 1 < 0) {
        return false;
    }
    x -= 1;
    copyDice();
    makeBottom(2);
    dice[1] = temp[5];
    dice[5] = temp[6];
    dice[2] = temp[1];

    return true;
}
// 남
bool func4() {
    if (x + 1 >= n) {
        return false;
    }

    x += 1;
    copyDice();
    makeBottom(5);
    dice[1] = temp[2];
    dice[2] = temp[6];
    dice[5] = temp[1];

    return true;
}

int main() {
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        int order;
        bool flag = false;
        memset(temp, 0, sizeof(temp));
        cin >> order;

        switch (order) {
        case 1:
            flag = func1();
            break;
        case 2:
            flag = func2();
            break;
        case 3:
            flag = func3();
            break;
        case 4:
            flag = func4();
            break;
        }

        if (flag) {
            cout << dice[1] << "\n";
        }
    }
    return 0;
}