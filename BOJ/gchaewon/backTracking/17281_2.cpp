#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int M = 9;
int n, ans = 0;
int base[3]; // 베이스 주자 여부, 없으면 0
vector<int> order;

struct Player {
    vector<int> result;
};
vector<Player> players(M + 1);
int visited[10];

int move(int num) {
    int temp_score = 0;
    // 원래있던 주자 이동
    for (int i = 2; i >= 0; i--) {
        if (base[i]) {
            // 홈으로 돌아오는 경우
            if (i + num >= 3) {
                temp_score += 1;
            } else { // 아직 돌아오지 못한 경우
                base[i + num] = 1;
            }
            // 원래있는 위치 지우기
            base[i] = 0;
        }
    }
    // 타자 이동
    if (num == 4) { // 홈런인경우
        temp_score += 1;
    } else {
        base[num - 1] = 1;
    }
    return temp_score;
}

int getScore() {
    int score = 0;
    int cur = 0; // 현재 타순

    // 이닝
    for (int i = 0; i < n; i++) {
        // 아웃 카운트, 베이스 초기화
        int out = 0;
        memset(base, 0, sizeof(base));

        // 3아웃 전까지 게임
        while (out < 3) {
            int result = players[order[cur]].result[i]; // 이번 타순의 선수 결과

            switch (result) {
            case 0:
                out += 1;
                break;
            case 1:
                score += move(1);
                break;
            case 2:
                score += move(2);
                break;
            case 3:
                score += move(3);
                break;
            case 4:
                score += move(4);
                break;
            }
            cur += 1; // 타순 갱신
            cur %= M;
        }
    }
    return score;
}

void backTracking(int cnt) {
    if (cnt > 9) { // 9번 타순까지 다 세웠다면, 점수 구하기
        int score = getScore();
        ans = max(ans, score);
        return;
    }

    if (cnt == 4) {
        order.push_back(1);

        backTracking(cnt + 1);

        order.pop_back(); // 벡터이므로 4번 타순이 고정 자리여도 원복해야, 벡터
                          // 길이 유지 가능
        return;
    }

    for (int i = 2; i <= 9; i++) { // 1번 선수제외하고 타선 세우기
        if (visited[i]) {          // 이미 세운 선수 제외
            continue;
        }
        // 추가
        visited[i] = 1;
        order.push_back(i);

        // 탐색
        backTracking(cnt + 1);

        // 원복
        visited[i] = 0;
        order.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= M; j++) {
            int r;
            cin >> r;
            players[j].result.push_back(r);
        }
    }

    backTracking(1);

    cout << ans;
    return 0;
}