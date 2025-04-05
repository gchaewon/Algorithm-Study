#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

#define X first
#define Y second
using namespace std;

struct Snake {
    deque<pair<int, int>> body; // 뱀 몸통 (머리~꼬리) 위치
    int d;                      // 뱀 진행 방향
};

vector<pair<int, int>> dir = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 동남서북 (시계방향)

int a[104][104]; // 보드, 0 = 빈칸, 1 = 사과, 2 = 뱀
char m[10004];   // m[i] = i초에 움직이는 방향 정보
int n, t = 0;    // 보드 사이즈, 총 걸린 시간

Snake s = {{{0, 0}}, 0};

void turn(char d) {
    if (d == 'L') { // 반시계 방향
        s.d -= 1;
        if (s.d < 0) {
            s.d += 4;
        }
    } else { // 시계 방향
        s.d += 1;
        if (s.d >= 4) {
            s.d %= 4;
        }
    }
}

bool go() {
    // 방향 변환 시간인지 확인 후 변환
    if (m[t] != 'N') {
        turn(m[t]);
    }

    // 머리 부분 이동 위치
    int dx = s.body[0].X + dir[s.d].X;
    int dy = s.body[0].Y + dir[s.d].Y;

    // 벽 or 자신의 몸과 부딪히는 경우
    if (dx < 0 || dx >= n || dy < 0 || dy >= n || a[dx][dy] == 2) {
        return false;
    }

    // 이동한 칸이 사과가 아닌 경우 꼬리 지우기, 맵 업데이트
    if (a[dx][dy] != 1) {
        pair<int, int> tail = s.body.back();
        a[tail.X][tail.Y] = 0;
        s.body.pop_back();
    }

    // 머리 추가, 맵 업데이트
    s.body.push_front({dx, dy});
    a[dx][dy] = 2;
    return true;
}

int main() {
    int k, l;
    memset(m, 'N', sizeof(m));

    cin >> n;
    cin >> k;

    // 사과 입력
    while (k--) {
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }

    // 뱀 이동 정보 저장
    cin >> l;
    while (l--) {
        int s;
        char d; // 뱀 s초, d 방향으로 회전
        cin >> s >> d;
        m[s] = d;
    }

    a[0][0] = 2; // 뱀 초기 위치 저장

    while (true) {
        bool flag = go();

        if (!flag) {
            cout << t + 1;
            break;
        }
        t++;
    }

    return 0;
}