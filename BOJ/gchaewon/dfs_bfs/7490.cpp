#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<string> ans;

int calc(string exps) {
    int result = 0;
    string temp = ""; // 공백 제거

    // 공백 제거
    for (auto c : exps) {
        if (c == ' ') {
            continue;
        }
        temp += c;
    }

    // 수식 계산
    string num = "";
    char op = ' ';

    for (auto c : temp) {
        if (c == '+' || c == '-') {
            if (op == ' ' || op == '+') {
                result += stoi(num);
            } else {
                result -= stoi(num);
            }
            op = c;
            num.clear();
        } else {
            num += c;
        }
    }
    // 남은 식 계산
    if (op == ' ' || op == '+') {
        result += stoi(num);
    } else {
        result -= stoi(num);
    }

    return result;
}
void dfs(int cnt, int n, string exps) {
    // n까지 수 추가한 경우 종료
    if (cnt == n) {
        if (calc(exps) == 0) {
            ans.push_back(exps);
            exps = "";
        }
        return;
    }

    // 아스키코드 순으로 추가
    dfs(cnt + 1, n, exps + " " + to_string(cnt + 1));
    dfs(cnt + 1, n, exps + "+" + to_string(cnt + 1));
    dfs(cnt + 1, n, exps + "-" + to_string(cnt + 1));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // 제일 첫 수는 포함해서 탐색
        dfs(1, n, "1");

        // 0이 되는 수식 출력
        for (auto a : ans) {
            cout << a << "\n";
        }
        ans.clear();
        cout << "\n";
    }

    return 0;
}