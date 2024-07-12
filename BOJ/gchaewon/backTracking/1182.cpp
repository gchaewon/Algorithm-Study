#include <iostream>
#include <vector>
using namespace std;

int n, s;
int answer = 0;
vector<int> v(20, 0);

void subseqSum(int k, int sum) {
    // 종료 조건
    if (k == n) {
        if (sum == s) {
            answer++;
        }
        return;
    }

    subseqSum(k + 1, sum);        // 집합에 포함하지 않는 경우
    subseqSum(k + 1, sum + v[k]); // 집합에 포함하는 경우
}
int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    subseqSum(0, 0);

    if (s == 0) {
        cout << answer - 1; // 공집합 제거
    } else {
        cout << answer;
    }
    return 0;
}