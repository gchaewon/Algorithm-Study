#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    int sum = 0;
    cin >> n >> k;
    set<int> coins;
    // dp[i] = i원을 만들기 위해 사용하는 동전 최소 개수
    vector<int> dp(k + 1, 0);

    // 입력
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.insert(coin);
        if (coin <= k) {
            dp[coin] = 1;
        }
    }

    for (int i = *coins.begin(); i <= k; i++) {
        set<int> temp; // i원을 만들 수 있는 동전 개수, 모든 경우
        if (dp[i] == 1) {
            continue;
        }
        for (auto coin : coins) {
            if (i - coin <= 0) { // 동전이 금액을 넘는 경우 제외
                continue;
            }
            // i-coin을 만들 수 있을 때만 포함
            if (dp[i - coin] > 0) {
                temp.insert(dp[i - coin]);
            }
        }

        if (temp.size() != 0) {
            dp[i] = *temp.begin() + 1;
        } else {
            dp[i] = -1; // i원을 만들 수 없으면 -1 저장
        }
    }

    cout << dp[k];

    return 0;
}