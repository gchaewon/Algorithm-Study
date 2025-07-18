#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, w, l, truck;
    cin >> n >> w >> l;

    queue<int> trucks;
    deque<pair<int, int>> bridge; // {들어온 시간, 트럭 무게}
    int t = 1;
    int weight = 0;

    while (n--) {
        cin >> truck;
        trucks.push(truck);
    }

    // 첫 차 다리에 놓기
    bridge.push_back({t, trucks.front()});
    weight += trucks.front();
    trucks.pop();

    // 다리가 빌 때까지 반복
    while (!bridge.empty()) {
        t++;
        // 지나간 트럭 처리
        while (!bridge.empty()) {
            if (t - bridge.front().first >= w) {
                weight -= bridge.front().second;
                bridge.pop_front();
            } else {
                break;
            }
        }

        // 새 트럭 놓기, 대기하는 트럭이 없으면 넘어감
        if (trucks.empty()) {
            continue;
        }

        int next = trucks.front();
        // 무게 조건 만족면 추가
        if (weight + next <= l) {
            weight += next;
            bridge.push_back({t, next});
            trucks.pop(); // 대기열에서 삭제
        }
    }
    cout << t;

    return 0;
}