#include <cstring>
#include <iostream>
using namespace std;

const int N = 3;
char board[N][N];
int o_cnt = 0, x_cnt = 0;

bool getWinner(char mark) {
    // 가로
    for (int x = 0; x < N; x++) {
        if (board[x][0] != mark) {
            continue;
        }
        if (board[x][0] == board[x][1] && board[x][1] == board[x][2]) {
            return true;
        }
    }
    // 세로
    for (int y = 0; y < N; y++) {
        if (board[0][y] != mark) {
            continue;
        }
        if (board[0][y] == board[1][y] && board[1][y] == board[2][y]) {
            return true;
        }
    }
    // 대각선
    if (board[0][0] == mark && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == mark && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkBoard() {
    bool is_empty = (x_cnt + o_cnt < 9);

    // 두번째 사람이 놓은 말이 더 많은 경우 불가
    if (x_cnt < o_cnt) {
        return false;
    }

    // X, O 이긴 사람 구하기
    bool o_win = getWinner('O');
    bool x_win = getWinner('X');

    // 둘 다 이길 수는  없음
    if (o_win && x_win) {
        return false;
    }

    // 놓을 자리가 없는 경우, 무조건 선 (X)가 이기거나, 무승부
    if (!is_empty) {
        // 놓을 자리가 없는 경우 반드시 X 턴에서 끝남
        if (x_cnt == o_cnt + 1 && (x_win || (!x_win && !o_win))) {
            return true;
        } else {
            return false;
        }
    }
    // 빈자리가 있지만 종료한 경우,
    // 무조건 한 명이 이겨야함 무승부 불가
    // X가 이김, X가 한 수 더 둬야함
    // O가 이김, O와 X 수 동일
    else {
        // 무승부 불가
        if (!x_win && !o_win) {
            return false;
        }
        if (x_win) {
            if (x_cnt == o_cnt + 1) {
                return true;
            } else {
                return false;
            }
        } else {
            if (x_cnt == o_cnt) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

int main() {
    while (true) {
        string line;
        memset(board, 0, sizeof(board));
        cin >> line;
        if (line == "end") {
            break;
        }

        o_cnt = 0, x_cnt = 0;

        for (int i = 0; i < N * N; i++) {
            board[i / N][i % N] = line[i];

            if (line[i] == 'X') {
                x_cnt++;
            } else if (line[i] == 'O') {
                o_cnt++;
            }
        }
        if (checkBoard()) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}