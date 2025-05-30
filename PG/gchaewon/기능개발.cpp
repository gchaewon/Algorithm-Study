#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int END = 100;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();

    vector<int> works = progresses;

    for (int i = 0; i < n; i++) {
        // 이미 완료한 작업은 건너뛰기
        if (works[i] >= END) {
            continue;
        }
        // 제일 앞 작업 완료까지 소요일 계산
        int day = ceil((END - works[i]) / float(speeds[i]));
        works[i] += day * speeds[i];
        int cnt = 1;

        // 뒷 작업 소요일 내에 완료된 것 개수 계산
        bool flag = true;
        for (int j = i + 1; j < n; j++) {
            works[j] += day * speeds[j];
            // 만약 이전 작업이 완료가 안된 경우 배포 불가
            if (works[j - 1] < END) {
                flag = false;
            }
            if (works[j] >= END && flag) {
                cnt++;
            }
        }
        // 완료한 작업 수 추가
        answer.push_back(cnt);
    }
    return answer;
}