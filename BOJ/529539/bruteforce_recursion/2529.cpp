#include <iostream>
#include <string>

using namespace std;

int n;
char arr[10];
bool used[10];
string maxNum = "";
string minNum = "9876543210";

void recursion(string s) {
	if (s.size() == n + 1) {
		maxNum = max(maxNum, s);
		minNum = min(minNum, s);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (used[i])
			continue;
		char sign = arr[s.size() - 1];
		int lastNum = s.back() - '0';
		if ((sign == '>' && lastNum < i) || (sign == '<' && lastNum > i))
			continue;
		used[i] = true;
		s.push_back(i + '0');
		recursion(s);
		s.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	string s = "";
	for (int i = 0; i <= 9; i++) {
		used[i] = true;
		s.push_back((i + '0'));
		recursion(s);
		s.pop_back();
		used[i] = false;
	}

	cout << maxNum << '\n';
	cout << minNum << '\n';
}