#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000
using namespace std;

struct ball {
	int color, size, idx;
};

bool compare(ball &a, ball &b) {
	if (a.size == b.size)
		return a.color < b.color;
	else
		return a.size < b.size;
}

int main() {
	int n, c, s;
	vector<ball> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c >> s;
		v.push_back({c, s, i});
	}
	sort(v.begin(), v.end(), compare);

	int sum = 0;
	int C[MAX];
	int S[MAX];
	int answer[MAX];
	for (int i = 0; i < n; i++) {
		sum += v[i].size;
		C[v[i].color] += v[i].size;
		S[v[i].size] += v[i].size;
		if (i != 0 && v[i].color == v[i - 1].color && v[i].size == v[i - 1].size) {
			answer[v[i].idx] = answer[v[i - 1].idx];
		} else {
			answer[v[i].idx] = sum - C[v[i].color] - S[v[i].size] + v[i].size;
		}
	}
	for (int i = 0; i < n; i++)
		cout << answer[i] << "\n";
}