#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 0;
    int n = truck_weights.size();
    int cur_w = 0; // 다리 위 트럭 무게

    queue<pair<int, int>> q; // {들어간 시간, 트럭 무게}
    vector<int> trucks = truck_weights;

    // 첫 트럭 추가
    q.push({0, trucks[0]});
    cur_w += trucks[0];
    trucks.erase(trucks.begin());

    // 다리 위에 트럭이 다 지나갈 때까지 반복
    while (!q.empty()) {
        t++;

        // 다리 위 트럭 검사, 지나갔으면 삭제
        if (t - q.front().first >= bridge_length) {
            cur_w -= q.front().second;
            q.pop();
        }

        // 대기 트럭 추가
        if (!trucks.empty()) {
            int truck = trucks.front();

            // 무게 조건 만족하는 경우 추가, 대기열에서 삭제
            if (cur_w + truck <= weight) {
                cur_w += truck;
                q.push({t, truck});
                trucks.erase(trucks.begin());
            }
        }
    }
    t += 1;

    return t;
}