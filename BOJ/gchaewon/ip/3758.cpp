#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int T;

struct Team {
    int id;
    int total_score;
    int submit_cnt;
    int last_submit;
    map<int, int> scores;
};

bool cmp(Team &a, Team &b) {
    if (a.total_score != b.total_score) {
        return a.total_score > b.total_score;
    }
    if (a.submit_cnt != b.submit_cnt) {
        return a.submit_cnt < b.submit_cnt;
    }
    return a.last_submit < b.last_submit;
}

int main() {
    cin >> T;

    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        vector<Team> teams(n + 1);

        // 점수 로그 입력 받
        for (int i = 1; i <= m; i++) {
            int id, prob_id, s;
            cin >> id >> prob_id >> s;

            teams[id].id = id;
            teams[id].scores[prob_id] = max(teams[id].scores[prob_id], s);
            teams[id].submit_cnt += 1;
            teams[id].last_submit = i;
        }

        // 팀 최종 점수 계산
        for (auto &team : teams) {
            int sum = 0;
            for (auto s : team.scores) {
                sum += s.second;
            }
            team.total_score = sum;
        }

        sort(teams.begin(), teams.end(), cmp);
        for (int i = 0; i < n; i++) {
            if (teams[i].id == t) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}