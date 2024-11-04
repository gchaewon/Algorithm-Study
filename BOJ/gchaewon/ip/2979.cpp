#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    int last = 0;
    int answer = 0;
    vector<int> sum(4, 0);
    vector<vector<int>> v(3, vector<int>(2, 0));
    vector<int> time(101, 0);

    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
            last = max(last, v[i][j]);
        }

        for (int j = v[i][0]; j < v[i][1]; j++) {
            time[j]++;
        }
    }

    for (int i = 1; i < last; i++) {
        sum[time[i]]++;
    }

    answer = sum[1] * a + sum[2] * b * 2 + sum[3] * c * 3;
    cout << answer;

    return 0;
}