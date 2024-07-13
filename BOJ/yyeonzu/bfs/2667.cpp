#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;

vector<vector<int>> map;
vector<vector<int>> visited;

vector<int> ans;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push({i, j});
    visited[i][j] = 1;
    cnt++;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = cur_x + dx[k];
            int ny = cur_y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny] || map[nx][ny] == 0)
                continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
            cnt++;
        }
    }
    ans.push_back(cnt);

    return;
}

int main()
{

    cin >> N;

    map.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
            map[i][j] = line[j] - '0';
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
                bfs(i, j);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

    return 0;
}