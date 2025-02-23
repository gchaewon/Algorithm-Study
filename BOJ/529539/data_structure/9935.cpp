#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, bomb, tmp = "";
	cin >> str >> bomb;
	int b_len = bomb.length();

	for (int i = 0; i < str.length(); i++) {
		tmp += str[i];
		if (tmp.length() < b_len)
			continue;
		bool flag = true;
		for (int j = 0; j < b_len; j++)
			if (tmp[tmp.length() - b_len + j] != bomb[j]) {
				flag = false;
				break;
			}
		if (flag)
			tmp.erase(tmp.end() - b_len, tmp.end());
	}

	if (tmp.length() == 0)
		cout << "FRULA";
	else
		cout << tmp;
}