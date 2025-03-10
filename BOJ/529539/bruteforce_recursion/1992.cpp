#include <iostream>
#include <string>

using namespace std;

string arr[64];
string answer = "";

void recursion(int n, int x, int y) {
	int total = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			total += arr[y + j][x + i] - '0';
	if (total == 0)
		answer += '0';
	else if (total == n * n)
		answer += '1';
	else {
		n /= 2;
		answer += '(';
		recursion(n, x, y);
		recursion(n, x + n, y);
		recursion(n, x, y + n);
		recursion(n, x + n, y + n);
		answer += ')';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	recursion(n, 0, 0);
	cout << answer;
}