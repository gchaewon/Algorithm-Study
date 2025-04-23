// union find 풀이
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
int p[204]; // i번 도시의 루트

int findParrent(int x) {
    if (p[x] == x) {
        return x; // 연결된 것이 없다면 자기 자신 리턴
    }
    return p[x] = findParrent(p[x]); // 루트 리턴
}

void unionNode(int x, int y) {
    x = findParrent(x);
    y = findParrent(y);

    // 루트가 작은 쪽 값으로 갱신
    if (x < y) {
        p[y] = x;
    } else {
        p[x] = y;
    }
}
int main() {
    int is_connect, start, root = -1;
    bool flag = true;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        p[i] = i; // 초기 루트는 자기 자신
    }

    // 노드 연결
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> is_connect;
            // 연결되어 있다면 union
            if (is_connect) {
                unionNode(i, j);
            }
        }
    }

    // 여행지 경로끼리 루트가 같은지 확인
    cin >> start;
    root = findParrent(start - 1);

    for (int i = 1; i < m; i++) {
        int cur;
        cin >> cur;
        cur -= 1;
        if (findParrent(root) != findParrent(cur)) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}