#include <cmath>
#include <iostream>
using namespace std;

int n;
int arr[16]; // 각 행(x)에서 퀸을 놓은 열(y) 저장
int answer = 0;

bool isSafe(int x, int y) {
    for (int i = 0; i < x; i++) { // x-1 행까지 퀸을 놓은 위치를 순회하며 확인
        // 같은 열이나 대각선인 경우 false
        if (arr[i] == y || abs(i - x) == abs(arr[i] - y)) {
            return false;
        }
    }
    return true;
}

void nQueen(int x) {
    if (x == n) { // 마지막 행까지 도착
        answer++;
        return;
    }
    for (int y = 0; y < n; y++) {
        if (isSafe(x, y)) {
            arr[x] = y;
            nQueen(x + 1); // 다음 행 호출
        }
    }
}

int main() {
    cin >> n;
    nQueen(0); // 0번째 행부터 시작
    cout << answer;
    return 0;
}
