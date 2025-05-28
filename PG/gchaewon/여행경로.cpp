#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n;
map<string, vector<pair<string, bool>>>
    infos; // {시작, {도착 공항 정보, 사용여부}}
vector<string> path;
set<vector<string>> paths;

void dfs(string cur, int cnt) {
    // 티켓 다 쓴 경우, 경로 추가 후 종료
    if (cnt == n) {
        paths.insert(path);
        return;
    }

    // 현재 공항에서 갈 수 있는 경로 탐색
    for (auto &next : infos[cur]) {
        // 사용한 티켓의 경우 제외
        if (next.second) {
            continue;
        }
        // 방문처리
        next.second = true;
        path.push_back(next.first);

        // 탐색
        dfs(next.first, cnt + 1);

        // 원복
        path.pop_back();
        next.second = false;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();

    // map에 티켓 정보 저장
    for (auto ticket : tickets) {
        infos[ticket[0]].push_back({ticket[1], false});
    }

    path.push_back("ICN");
    dfs("ICN", 0);

    // 사전 순으로 앞선 경로 리턴
    answer = *paths.begin();
    return answer;
}