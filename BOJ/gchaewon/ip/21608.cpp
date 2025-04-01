#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n;
int m[24][24];
int satisfied[] = {0, 1, 10, 100, 1000};
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
map<int, set<int>> like_map;

struct seat {
    int x, y;                // 위치
    int like_cnt, empty_cnt; // 인근 좋아하는 학생 칸 수, 인근 빈 칸 수
};

bool cmp(struct seat &a, struct seat &b) {
    // 1. 인접 칸 중 좋아하는 학생 수 기준 내림차순
    if (a.like_cnt == b.like_cnt) {
        // 2. 인접 칸 중 빈 칸 기준 내림차순
        if (a.empty_cnt == b.empty_cnt) {
            // 3. 행 번호 오름차순
            if (a.x == b.x) {
                // 4. 열 번호 오름차순
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.empty_cnt > b.empty_cnt;
    }
    return a.like_cnt > b.like_cnt;
}

void findSeat(int id, set<int> like) {
    vector<struct seat> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 비어있지 않은 칸 넘어가기
            if (m[i][j]) {
                continue;
                // 빈 칸인 경우
            } else {
                int like_cnt = 0, empty_cnt = 0;

                // 주변 4칸 조회
                for (auto d : dir) {
                    int dx = i + d.first;
                    int dy = j + d.second;
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                        continue;
                    }
                    // 좌석에 앉은 학생이 있는 경우, 좋아하는 학생인지 확인
                    if (m[dx][dy]) {
                        if (like.find(m[dx][dy]) != like.end()) {
                            like_cnt++;
                        }
                        // 빈 의자라면 빈 갯수 더하기
                    } else {
                        empty_cnt++;
                    }
                }
                v.push_back({i, j, like_cnt, empty_cnt});
            }
        }
    }

    // 조건에 제일 잘 맞는 자리로 정렬
    sort(v.begin(), v.end(), cmp);

    // 자리 배정
    int x = v[0].x;
    int y = v[0].y;
    m[x][y] = id;
}

int counter() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = m[i][j];
            int cnt = 0;

            // 주변 4칸 조회
            for (auto d : dir) {
                int dx = i + d.first;
                int dy = j + d.second;
                if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                    continue;
                }
                // 좋아하는 학생의 번호라면 개수 카운팅
                if (like_map[cur].find(m[dx][dy]) != like_map[cur].end()) {
                    cnt++;
                }
            }
            sum += satisfied[cnt];
        }
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int id = 0;
        set<int> like;
        cin >> id;
        for (int j = 0; j < 4; j++) {
            int like_num;
            cin >> like_num;
            like.insert(like_num);
        }
        like_map.insert({id, like});
        findSeat(id, like);
    }
    cout << counter();

    return 0;
}