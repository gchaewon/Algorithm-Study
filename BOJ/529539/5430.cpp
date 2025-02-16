#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		string command, str;
		deque<int> dq;
		cin >> command;
		cin >> n;
		cin >> str;

		string tmp;
		for (int i = 0; i < str.length(); i++)
			if (isdigit(str[i]))
				tmp += str[i];
			else {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}

		bool reverse = false, error = false;
		for (auto com : command) {
			if (com == 'R')
				reverse = !reverse;
			else {
				if (!dq.empty())
					reverse ? dq.pop_back() : dq.pop_front();
				else {
					error = true;
					break;
				}
			}
		}

		if (error)
			cout << "error" << "\n";
		else {
			cout << "[";
			if (!dq.empty() && !reverse) {
				for (auto it = dq.begin(); it != dq.end(); it++)
					it == dq.end() - 1 ? cout << *it : cout << *it << ',';
			} else if (!dq.empty() && reverse) {
				for (auto it = dq.rbegin(); it != dq.rend(); it++)
					it == dq.rend() - 1 ? cout << *it : cout << *it << ',';
			}
			cout << "]\n";
		}
	}
}