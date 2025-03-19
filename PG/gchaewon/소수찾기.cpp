#include <bits/stdc++.h>
using namespace std;
const int max_num = 9999999;
vector<int> prime(max_num + 1, -1);

void findPrime() {
    prime[0] = 0;
    prime[1] = 0;
    prime[2] = 1;

    for (int i = 3; i <= max_num; i++) {
        if (prime[i] != -1) {
            continue;
        }
        // 짝수 배수 처리
        if (i % 2 == 0) {
            for (int j = 1; i * j <= max_num; j++) {
                prime[i * j] = 0;
            }
            // 홀수 및 배수 처리
        } else {
            prime[i] = 1;
            for (int j = 2; i * j <= max_num; j++) {
                prime[i * j] = 0;
            }
        }
    }
}
int makeNum(string numbers) {
    int n = numbers.size();
    set<int> s;

    // 비트마스킹으로 숫자 뽑기 경우의 수
    for (int i = 0; i < (1 << n); i++) {
        vector<int> picked;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                picked.push_back(numbers[j] - '0');
            }
        }
        if (picked.size() == 0) {
            continue;
        }
        sort(picked.begin(), picked.end());

        // 뽑은 수 순열
        do {
            string num;
            for (int k = 0; k < picked.size(); k++) {
                num += to_string(picked[k]);
            }
            // 소수 여부 확인 후 중복제거
            if (prime[stoi(num)]) {
                s.insert(stoi(num));
            }
        } while (next_permutation(picked.begin(), picked.end()));
    }
    return s.size();
}

int solution(string numbers) {
    int answer = 0;

    findPrime();
    answer = makeNum(numbers);

    return answer;
}