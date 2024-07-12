#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    pair<long long, long long> start = {x, y};
    pair<long long, long long> end = {x, y};

    // 쿼리 역순으로 탐색하며, 시작 가능 범위 좁히기
    for (int i = queries.size() - 1; i >= 0; i--) {
        int dir = queries[i][0];
        int dist = queries[i][1];

        // 쿼리에 따라 끝, 시작 지점 이동하고 범위를 벽에 부딪히면(0, n-1, m-1
        // 일 때) 조정하기
        switch (dir) {
        case 0:
            if (start.Y != 0)
                start.Y += dist;
            end.Y = min((long long)m - 1, end.Y + dist);
            break;
        case 1:
            if (end.Y != m - 1)
                end.Y -= dist;
            start.Y = max(0LL, start.Y - dist);
            break;
        case 2:
            if (start.X != 0)
                start.X += dist;
            end.X = min((long long)n - 1, end.X + dist);
            break;
        case 3:
            if (end.X != n - 1)
                end.X -= dist;
            start.X = max(0LL, start.X - dist);
            break;
        }

        // 범위를 벗어나면 종료
        if (start.X > end.X || start.Y > end.Y)
            return 0;
    }

    // 가능한 시작점의 개수 계산 후 반환
    return (end.X - start.X + 1) * (end.Y - start.Y + 1);
}
