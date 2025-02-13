#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
using namespace std;

vector<vector<pair<int, int>>> shapes = {
    // ㅡ
    {{0, 1}, {0, 1}, {0, 1}},
    {{1, 0}, {1, 0}, {1, 0}},
    // ㅁ
    {{0, 1}, {1, 0}, {0, -1}},
    // L
    {{1, 0}, {1, 0}, {0, 1}},
    {{1, 0}, {1, 0}, {0, -1}},
    {{0, -1}, {1, 0}, {1, 0}},
    {{0, 1}, {1, 0}, {1, 0}},
    {{0, 1}, {0, 1}, {-1, 0}},
    {{1, 0}, {0, 1}, {0, 1}},
    {{0, 1}, {0, 1}, {1, 0}},
    {{-1, 0}, {0, 1}, {0, 1}},
    // 번개 모양
    {{1, 0}, {0, 1}, {1, 0}},
    {{1, 0}, {0, -1}, {1, 0}},
    {{0, 1}, {-1, 0}, {0, 1}},
    {{0, 1}, {1, 0}, {0, 1}},

    // ㅜ
    {{0, 1}, {1, 0}, {-1, 1}},
    {{0, 1}, {-1, 0}, {1, 1}},
    {{1, 0}, {0, 1}, {1, -1}},
    {{0, 1}, {-1, 0}, {2, 0}}};

int n, m;

int find_tetro(pair<int, int> start, vector<vector<int>> &v) {
    int max_tetro = 0;
    int x = start.X;
    int y = start.Y;

    int count = 0;
    for (auto shape : shapes) {
        count++;

        int sum = v[x][y];
        bool is_valid = true;
        int dx = x;
        int dy = y;

        for (auto d : shape) {

            dx += d.X;
            dy += d.Y;

            if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
                is_valid = false;
                continue;
            }

            sum += v[dx][dy];
        }
        if (is_valid) {
            max_tetro = max(max_tetro, sum);
        }
    }
    return max_tetro;
}

int main() {
    int answer = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer = max(answer, find_tetro({i, j}, v));
        }
    }
    cout << answer;
    return 0;
}