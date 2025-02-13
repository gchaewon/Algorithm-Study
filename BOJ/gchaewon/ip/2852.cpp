#include <iostream>
#include <string>

using namespace std;
int main() {
    int n, team, cnt1 = 0, cnt2 = 0, t1 = 0, t2 = 0;
    int pre_time = 0, cur_time = 0;
    string time;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> team >> time;
        cur_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));

        if (cnt1 > cnt2) {
            t1 += cur_time - pre_time;
        } else if (cnt1 < cnt2) {
            t2 += cur_time - pre_time;
        }
        pre_time = cur_time;

        if (team == 1) {
            cnt1 += 1;
        } else {
            cnt2 += 1;
        }
    }

    if (cnt1 > cnt2) {
        t1 += ((48 * 60) - pre_time);
    } else if (cnt1 < cnt2) {
        t2 += ((48 * 60) - pre_time);
    }

    printf("%02d:%02d\n", t1 / 60, t1 % 60);
    printf("%02d:%02d\n", t2 / 60, t2 % 60);

    return 0;
}