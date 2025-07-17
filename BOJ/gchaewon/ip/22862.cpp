#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, num;
    int ans = 0;
    cin >> n >> k;
    vector<int> odds(n + 1, 0);  // i번째 원소까지 홀수 개수
    vector<int> evens(n + 1, 0); // i번째 원소까지 짝수 개수

    for (int i = 1; i <= n; i++) {
        cin >> num;

        odds[i] = odds[i - 1];
        if (num % 2 != 0) {
            odds[i] += 1;
        }
        evens[i] = i - odds[i];
    }

    // 투포인터 사용
    int left = 1, right = 1;

    // 두 포인터가 만날때까지 반복
    while (left <= right && right <= n) {
        int odd = odds[right] - odds[left - 1];
        int even = evens[right] - evens[left - 1];

        // 지울 수 있는 개수 보다 작거나 같으면, 전체 길이 늘림
        if (odd <= k) {
            ans = max(ans, even);
            right++;
        } else { // 지울 수 있는 개수보다 크면, 전체 길이 줄임
            left++;
        }
    }
    cout << ans;
    return 0;
}