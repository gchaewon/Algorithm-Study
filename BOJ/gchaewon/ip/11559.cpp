#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define X first
#define Y second
using namespace std;

const int n = 12, m = 6;
int ans = 0;
char board[n][m], temp[n][m];
int visited[n][m];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
set<char> colors = {'R', 'G', 'B', 'P', 'Y'};

vector<pair<int, int>> bfs(char color, pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.X][start.Y] = 1;
    vector<pair<int, int>> trace;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        trace.push_back({x, y});
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy]) {
                continue;
            }

            if (board[dx][dy] != color) {
                continue;
            }
            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }

    return trace;
}

// 디버깅용
void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

bool removePuyo() {
    bool is_remove = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 푸요에 해당하는 알파벳인 경우 bfs로 지울 영역 찾기
            if (colors.find(board[i][j]) != colors.end()) {
                vector<pair<int, int>> removed = bfs(board[i][j], {i, j});

                // 영역 크기가 4 이상인 경우만 삭제
                if (removed.size() >= 4) {
                    is_remove = true;
                    // board에 X 표시하기
                    for (auto r : removed) {
                        board[r.X][r.Y] = 'X';
                    }
                }
            }
        }
    }
    return is_remove;
}
void copyBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = board[i][j];
        }
    }
}

// X 표시 바탕으로 지워야하는 부분 반영하는 함수
void updateBoard() {
    // 왼쪽 -> 오른쪽으로 세로 줄별로 업데이트
    // 삭제할 영역이 두 개 이상일 수 있으므로, 한 줄을 문자열에 넣고 처리

    for (int y = 0; y < m; y++) {
        string line;
        int idx = -1;

        for (int x = 0; x < n; x++) {
            line += board[x][y];

            // 나눌 인덱스 찾기 (.가 아닌 첫 번째 푸요 위치)
            if (board[x][y] != '.' && idx == -1) {
                idx = x;
            }
        }

        // . 인 부분과 아닌 부분 두 개로 나누기
        // ex) ....  , BXBBPRXX
        string line1 = line.substr(0, idx);
        string line2;
        int cnt = 0;

        for (int i = idx; i < n; i++) {
            // X 값은 제외
            if (line[i] == 'X') {
                cnt++;
                continue;
            }
            line2 += line[i];
        }

        line.clear();

        // 삭제한 푸요만큼 앞에 . 추가하기
        for (int i = 0; i < cnt; i++) {
            line += '.';
        }
        line += line1 + line2;

        // 보드에 업데이트
        for (int x = 0; x < n; x++) {
            board[x][y] = line[x];
        }
    }
}
int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        if (!removePuyo()) {
            break;
        }
        ans++; // 연쇄 카운트

        copyBoard();
        updateBoard();
        memset(visited, 0, sizeof(visited));
    }

    cout << ans;

    return 0;
}