#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int M = 9;
int n, ans = 0;
int base[3]; // 베이스 주자 여부, 없으면 0

struct Player {
    vector<int> result;
};
vector<Player> players(M + 1);

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

int getScore(vector<int> order) {
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

int main() {
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= M; j++) {
            int r;
            cin >> r;
            players[j].result.push_back(r);
        }
    }
    for (int i = 1; i <= M; i++) {
        arr.push_back(i);
    }

    do {
        vector<int> order; // 뽑은 타순 저장
        bool flag = true;
        for (int i = 0; i < M; i++) {
            // 4번타순에 1번이 아닌 경우 제외
            if (order.size() == 3 && arr[i] != 1) {
                flag = false;
                break;
            }
            order.push_back(arr[i]);
        }
        // 1번 선수가 4번타순일 때만 수행
        if (!flag) {
            continue;
        }
        int score = getScore(order);
        ans = max(ans, score); // 최고점 갱신
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans;
    return 0;
}