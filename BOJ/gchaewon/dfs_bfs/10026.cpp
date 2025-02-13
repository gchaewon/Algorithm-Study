#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

int n;
vector<char> color = {'R', 'B', 'G'};
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(vector<vector<char>> &map, char color, pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        map[x][y] = 'O'; // 방문처리
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if ((nx < 0 || nx >= n || ny < 0 || ny >= n))
                continue;
            if (map[nx][ny] != color)
                continue;

            q.push({nx, ny});
            map[nx][ny] = 'O';
        }
    }
}

void findArea(int option, vector<vector<char>> &map) {
    int count = 0;
    // 색별로 bfs 이중 for문으로 bfs 호출 횟수 (영역 개수) 구하기
    for (int i = 0; i < option; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (color[i] == map[j][k]) {
                    pair<int, int> start = make_pair(j, k);
                    bfs(map, color[i], start);
                    count++;
                }
            }
        }
    }
    cout << count << " ";
}

int main() {
    string line;
    getline(cin, line);
    n = stoi(line);
    vector<vector<char>> map(n, vector<char>(n, ' '));
    vector<vector<char>> cb_map(n, vector<char>(n, ' '));

    // 입력
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j];
            if (line[j] == 'G') {
                cb_map[i][j] = 'R';
            } else {
                cb_map[i][j] = line[j];
            }
        }
    }

    findArea(3, map);
    findArea(2, cb_map);

    return 0;
}