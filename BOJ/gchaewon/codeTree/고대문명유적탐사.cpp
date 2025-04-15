#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int n = 5, m, k;
int board[5][5], temp_board[5][5], turned_board[5][5];
int visited[5][5];
vector<pair<int, int>> found;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<int> wall;

struct Turn {
    int cx, cy; // 중심 좌표
    int angle;  // 회전 각도
    int value;  // 1차 획득 가치
};

// 회전 방식 정렬용
bool cmp(Turn &a, Turn &b) {
    if (a.value != b.value) {
        return a.value > b.value;
    }
    if (a.angle != b.angle) {
        return a.angle < b.angle;
    }
    if (a.cy != b.cy) {
        return a.cy < b.cy;
    }
    return a.cx < b.cx;
}
// 유적 추가할 위치 정렬용
bool cmp2(pair<int, int> &a, pair<int, int> &b) {
    if (a.Y != b.Y) {
        return a.Y < b.Y;
    }
    return a.X > b.X;
}

void copyBoardtoTurned() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            turned_board[i][j] = board[i][j];
        }
    }
}
void copyTurnedtoTemp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp_board[i][j] = turned_board[i][j];
        }
    }
}

// 내부 격자 3 * 3 시계 방향 90도만큼 회전
void turnBoard(int cx, int cy) {
    int l = 3;
    int sx = cx - 1, sy = cy - 1;

    // 그외 부분 채우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            turned_board[i][j] = temp_board[i][j];
        }
    }

    // 회전 부분 반영
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            turned_board[sx + j][sy + l - i - 1] = temp_board[sx + i][sy + j];
        }
    }
}

int bfs(int sx, int sy) {
    int cnt = 0;
    visited[sx][sy] = 1;
    vector<pair<int, int>> temp_found;
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        cnt++;
        temp_found.push_back({x, y});

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy]) {
                continue;
            }
            if (turned_board[dx][dy] != turned_board[sx][sy]) {
                continue;
            }
            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }
    if (cnt > 2) {
        for (auto t : temp_found) {
            found.push_back(t);
        }
        return cnt;
    }
    return 0;
}

// 특정 중심좌표일 때 최대 1차 가치내는 회전 각도, 구한 값
Turn getBoardValue(int cx, int cy) {
    Turn best_turn = {cx, cy, 0, 0};

    // 90 180 270도 회전
    for (int angle = 1; angle <= 3; angle++) {
        // 5 * 5 배열 복사 (원본 -> temp_board)
        memset(temp_board, 0, sizeof(temp_board));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp_board[i][j] = board[i][j];
            }
        }
        for (int r = 0; r < angle; r++) {
            turnBoard(cx, cy);
            copyTurnedtoTemp(); // 돌고 나서 temp에 업데이트
        }

        // 1차 유물 획득 가치 구하기
        // turned_board로 bfs
        int temp_value = 0;
        memset(visited, 0, sizeof(visited));
        found.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    temp_value += bfs(i, j);
                }
            }
        }
        // 더 많은 가치를 얻는 각도로 갱신
        if (temp_value > best_turn.value) {
            best_turn.angle = angle;
            best_turn.value = temp_value;
        }
    }
    return best_turn;
}

bool chooseBoard() {
    // 회전 중심좌표 브루트 포스
    vector<Turn> turns;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            turns.push_back(getBoardValue(i, j));
        }
    }
    // 최적 방식 구하기
    sort(turns.begin(), turns.end(), cmp);
    Turn best_turn = turns[0];

    // 구한 방식의 최대 가치가 0인 경우 (찾을 수 없음)
    if (best_turn.value == 0) {
        return false;
    }

    // 구한 방식으로 회전 board에 반영
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp_board[i][j] = board[i][j];
        }
    }

    for (int r = 0; r < best_turn.angle; r++) {
        turnBoard(best_turn.cx, best_turn.cy);
        copyTurnedtoTemp();
    }

    // 최종 결과 반영
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = turned_board[i][j];
        }
    }
    return true;
}

int findTreasure() {
    int value = 0;
    copyBoardtoTurned();
    memset(visited, 0, sizeof(visited));
    found.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                value += bfs(i, j);
            }
        }
    }
    return value;
}

void updateTreasure() {
    vector<pair<int, int>> location = found;
    sort(location.begin(), location.end(), cmp2);

    for (auto l : location) {
        board[l.X][l.Y] = wall.front();
        wall.pop();
    }
}

int main() {
    cin >> k >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        wall.push(value);
    }

    while (k--) {
        int turn_value = 0;
        // 1. 탐사 진행, 격자 선택 및 회전
        if (!chooseBoard()) {
            break;
        }
        int a = 0;
        while (true) {
            // 2. 유물 획득, 획득 가능한 유물이 없는 경우 0, 탐사 반복
            int temp_value = findTreasure();
            turn_value += temp_value;
            if (!temp_value) {
                break;
            };
            // 2-1. 유물 채워넣기
            updateTreasure();
        }
        cout << turn_value << " ";
    }

    return 0;
}