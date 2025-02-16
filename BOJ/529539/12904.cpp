#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	while (s.length() < t.length()) {
		if (t[t.length() - 1] == 'A')
			t.pop_back();
		else if (t[t.length() - 1] == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if (t == s)
		cout << 1;
	else
		cout << 0;
}