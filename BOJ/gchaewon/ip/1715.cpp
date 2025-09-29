#include <iostream>
#include <queue>
using namespace std;

int n;
long long ans = 0;
priority_queue<int, vector<int>, greater<int>>
    pq; // 최소 힙 (오름차순 우선순위큐 사용)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1) { // 카드 묶음이 2개 이상일 때만 실행
        // 제일 작은 묶음 2개 고르기
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans += a + b;   // 카드 비교 횟수 더하기
        pq.push(a + b); // 새로 만든 카드 묶음 추가
    }

    cout << ans;

    return 0;
}
