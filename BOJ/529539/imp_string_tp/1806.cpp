#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

int main() {
	int n, target;
	cin >> n >> target;
	int arr[MAX];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0, right = 0;
	int sum = arr[0];
	int len = n + 1;
	while (left <= right && right < n) {
		if (sum < target)
			sum += arr[++right];
		else {
			len = min(len, right - left + 1);
			sum -= arr[left++];
		}
	}

	if (len == n + 1)
		cout << 0;
	else
		cout << len;
}