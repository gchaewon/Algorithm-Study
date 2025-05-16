#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, int> m; // {코스, 주문 횟수}

void getComb(string order, int p) {
    int n = order.size();
    vector<int> sub_arr(n, 1);
    set<string> combs;

    sort(order.begin(), order.end());

    for (int i = 0; i < p; i++) {
        sub_arr[i] = 0;
    }

    do {
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (sub_arr[i] == 0) {
                temp += order[i];
            }
        }
        sort(temp.begin(), temp.end());
        combs.insert(temp);
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    for (auto comb : combs) {
        m[comb]++;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 손님의 주문에서 코스 요리 메뉴 갯수만큼 뽑아서 조합 만들기
    for (auto c : course) {
        for (auto order : orders) {
            if (order.size() < c) {
                continue;
            }
            getComb(order, c);
        }
    }

    map<int, vector<pair<int, string>>>
        course_comb; // {주문 길이, {주문 횟수, 주문 배열}}

    // 만든 코스를 주문 길이 기준으로 맵에 저장
    for (auto i : m) {
        string course_name = i.first;
        int order_num = i.second;
        course_comb[course_name.size()].push_back({order_num, course_name});
    }

    for (auto c : course) {
        // 요리 c개 코스가 없을 때 제외
        if (!course_comb[c].size()) {
            continue;
        }

        // 주문 횟수 기준으로 정렬
        sort(course_comb[c].rbegin(), course_comb[c].rend());
        int max_order = course_comb[c]
                            .front()
                            .first; // 요리 c개 코스 중 가장 많이 주문한 횟수

        // 최소 주문 횟수 기준 불충족시 제외
        if (max_order < 2) {
            continue;
        }

        // 가장 많이 주문한 횟수 메뉴 다 추가
        for (auto comb : course_comb[c]) {
            if (comb.first < max_order) {
                break;
            }
            answer.push_back(comb.second);
        }
    }

    // 코스요리 메뉴 이름순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}