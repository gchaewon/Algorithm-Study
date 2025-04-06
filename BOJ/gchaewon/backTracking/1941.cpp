#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

const int N = 5, M = 7;
char a[N][N];
int ans = 0;
int visited[N][N];
int picked[N][N];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void check(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    memset(visited, 0, sizeof(visited));
    visited[start.X][start.Y] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if (cnt == M) {
            ans++;
            return;
        }
        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= N || dy < 0 || dy >= N) {
                continue;
            }
            // 이미 지나갔거나, 뽑은 위치가 아닌 경우 넘어감
            if (visited[dx][dy] || !picked[dx][dy]) {
                continue;
            }
            cnt += 1;
            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
        }
    }

    // 25개 중 7개 뽑기
    vector<int> sub_arr(25, 1);
    for (int i = 0; i < M; i++) {
        sub_arr[i] = 0;
    }

    do {
        memset(picked, 0, sizeof(picked)); // 뽑힌 위치 1로 표시
        int start_x = 0, start_y = 0;
        int scnt = 0;
        for (int i = 0; i < N * N; i++) {
            int x = i / N;
            int y = i % N;

            if (sub_arr[i] == 0) {
                picked[x][y] = 1;
                start_x = x;
                start_y = y;
                if (a[x][y] == 'S') {
                    scnt++;
                }
            }
        }

        // 이다솜파가 4명 미만일 때 X
        if (scnt < 4) {
            continue;
        }
        // 뽑은 학생들이 연결되어 있는지 확인
        check({start_x, start_y});
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;

    return 0;
}
// 문제 핵심 십자 모형은 백트래킹으로 생성 불가 -> 조합+BFS
// 1. 학생 7명 뽑기 (이다솜파 4명 미만 제외)
// 2. bfs로 연결되어 있는지 확인
// 3. 연결되어 있으면 경우의수+1