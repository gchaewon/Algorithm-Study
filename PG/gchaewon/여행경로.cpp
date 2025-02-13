#include <algorithm>
#include <vector>

using namespace std;

vector<int> visited(10001, 0);
vector<string> answer;

bool dfs(int n, string cur, vector<vector<string>> tickets) {
    if (n == tickets.size()) {
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == cur && !visited[i]) {
            visited[i] = 1;
            answer.push_back(tickets[i][1]);
            if (dfs(n + 1, tickets[i][1], tickets)) {
                return true;
            }
            // back tracking
            visited[i] = 0;
            answer.pop_back();
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs(0, "ICN", tickets);

    return answer;
}