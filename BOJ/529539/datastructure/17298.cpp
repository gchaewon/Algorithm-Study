#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> answer(n, -1);
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
		if (!s.empty())
			answer[i] = s.top();
		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
}
