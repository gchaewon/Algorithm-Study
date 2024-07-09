#include <iostream>
using namespace std;

int n, m;
int arr[10];     // 수열 담는 배열
bool isused[10]; // 수 사용 여부를 저장

// 재귀 함수
void func(int k) {
    if (k == m) { // base condition, m개의 수열을 만들면 종료
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " "; // 수열 출력하기
        }
        cout << "\n";
        return;
    }
    // k가 아닌 경우
    for (int i = 1; i <= n; i++) {
        if (!isused[i]) { // 사용된 수가 아니면,
            // 재귀 호출 전, 수열에 추가하고, 상태 변경
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            // 재귀 호출 이후, 원래 i로 돌아와서 사용하지 않는 상태로 변경
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
}
