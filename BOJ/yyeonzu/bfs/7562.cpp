#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void bfs(int x1, int y1, int x2, int y2, int I, vector<vector<int>> &dist, vector<vector<int>> &visited)
{
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = 1;

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (ny < 0 || ny >= I || nx < 0 || nx >= I)
                continue;
            if (visited[nx][ny])
                continue;
            dist[nx][ny] = dist[xx][yy] + 1;
            if (nx == x2 && ny == y2)
                return;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int I, x1, y1, x2, y2;
        cin >> I;

        vector<vector<int>> visited(I, vector<int>(I, 0));
        vector<vector<int>> dist(I, vector<int>(I, 0));

        cin >> x1 >> y1;
        cin >> x2 >> y2;

        dist[x1][y1] = 0;
        bfs(x1, y1, x2, y2, I, dist, visited);
        cout << dist[x2][y2] << "\n";
    }

    return 0;
}
