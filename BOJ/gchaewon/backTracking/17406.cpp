#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m, k, min_result = INT_MAX;
int const_a[54][54], a[54][54], temp[54][54];

struct Turn {
    int r, c, s;
};

vector<Turn> turns, orders;

void copyA() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }
}
void copyConst() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = const_a[i][j];
        }
    }
}

// 회전 연산 함수
void simulator(Turn t) {
    int r = t.r - 1;
    int c = t.c - 1;
    int s = t.s;

    // 초기 위치 지정
    // 1  2
    // 3  4
    pair<int, int> p1 = {r - s, c - s};
    pair<int, int> p2 = {r - s, c + s};
    pair<int, int> p3 = {r + s, c - s};
    pair<int, int> p4 = {r + s, c + s};

    // 사각형 만족할 때까지만 반복
    while (p1.X < p3.X && p1.Y < p2.Y) {
        // >
        for (int y = p1.Y + 1; y <= p2.Y; y++) {
            a[p1.X][y] = temp[p1.X][y - 1];
        }

        // V
        for (int x = p2.X + 1; x <= p4.X; x++) {
            a[x][p2.Y] = temp[x - 1][p2.Y];
        }

        // <
        for (int y = p4.Y - 1; y >= p3.Y; y--) {
            a[p4.X][y] = temp[p4.X][y + 1];
        }

        // ^
        for (int x = p3.X - 1; x >= p1.X; x--) {
            a[x][p3.Y] = temp[x + 1][p3.Y];
        }

        // 크기 줄이기 (꼭짓점 이동)
        p1 = {p1.X + 1, p1.Y + 1};
        p2 = {p2.X + 1, p2.Y - 1};
        p3 = {p3.X - 1, p3.Y + 1};
        p4 = {p4.X - 1, p4.Y - 1};
    }
}
int getResult() {
    int result = INT_MAX;

    for (int i = 0; i < n; i++) {
        int row_result = 0;
        for (int j = 0; j < m; j++) {
            row_result += a[i][j];
        }
        result = min(result, row_result);
    }
    return result;
}
int main() {
    cin >> n >> m >> k;
    vector<int> sub_arr(k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> const_a[i][j];
            a[i][j] = const_a[i][j];
        }
    }

    // 회전 정보 입력 받기
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        turns.push_back({r, c, s});
        sub_arr[i] = i;
    }

    // 연산 순서 모든 경우 구하기
    do {
        copyConst(); // 원본 a 배열 복사
        orders.clear();

        for (int i = 0; i < k; i++) {
            orders.push_back(turns[sub_arr[i]]);
        }

        // 회전 연산
        for (auto order : orders) {
            copyA(); // 내부 원본 a 배열 복사
            simulator(order);
        }

        int result = getResult(); // 연산 후 배열의 최솟값 구하기
        min_result = min(min_result, result);

    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << min_result;

    return 0;
}