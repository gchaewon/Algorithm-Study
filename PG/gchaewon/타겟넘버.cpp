#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;

    vector<vector<int>> tree;

    tree.push_back({0});

    for (int i = 0; i < numbers.size(); i++) {
        vector<int> t;
        for (auto &j : tree[i]) {
            int a = j + numbers[i];
            int b = j - numbers[i];
            t.push_back(a);
            t.push_back(b);
            if ((a == target || b == target) && i == numbers.size() - 1)
                answer++;
        }
        tree.push_back(t);
    }
    return answer;
}