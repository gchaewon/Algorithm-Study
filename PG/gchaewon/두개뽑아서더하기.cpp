#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> m; // {정수, 정수 갯수}
    set<int> answer_s;
    set<int> number_s;

    // 정수 배열에서 같은 수 갯수 카운팅
    for (auto num : numbers) {
        m[num]++;
        number_s.insert(num);

        // 같은 수가 2개 이상이면, 같은수끼리 더하는 경우 추가
        if (m[num] > 1) {
            answer_s.insert(num * 2);
        }
    }

    // 정수 배열 중복 제거
    numbers.clear();
    for (auto number : number_s) {
        numbers.push_back(number);
    }

    vector<int> sub_arr(number_s.size(), 1);
    sub_arr[0] = sub_arr[1] = 0;

    // 중복 제거된 배열에서 2개씩 뽑아서 더한 값 set에 넣기
    do {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (sub_arr[i] == 0) {
                sum += numbers[i];
            }
        }
        answer_s.insert(sum);
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    // vector에 저장
    for (auto a : answer_s) {
        answer.push_back(a);
    }

    return answer;
}