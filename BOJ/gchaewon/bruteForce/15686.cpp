#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51];
int min_sum = INT_MAX;
vector<pair<int, int>> store; // 치킨 가게 저장
vector<pair<int, int>> house; // 집 저장

int findDist(vector<pair<int, int>> selected_store) {
    int sum = 0;
    for (auto h : house) {
        int dist = 500;
        for (auto s : selected_store) {
            int temp_dist = abs(h.first - s.first) + abs(h.second - s.second);
            dist = min(dist, temp_dist);
        }
        sum += dist;
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                store.push_back({i, j});
            } else if (arr[i][j] == 1) {
                house.push_back({i, j});
            }
        }
    }

    vector<int> sub_arr(store.size(), 1);
    for (int i = 0; i < m; i++) {
        sub_arr[i] = 0;
    }
    // 치킨 가게 중 m 곳 고르기
    do {
        vector<pair<int, int>> selected;
        for (int i = 0; i < store.size(); i++) {
            if (sub_arr[i] == 0) {
                selected.push_back(store[i]);
            }
        }
        int temp_sum = findDist(selected);
        min_sum = min(min_sum, temp_sum);
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << min_sum;
    return 0;
}