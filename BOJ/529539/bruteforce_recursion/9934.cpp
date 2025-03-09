#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int height;
vector<int> arr;
vector<vector<int>> tree;

void recursion(int start, int end, int level) {
	if (level == height)
		return;
	int mid = floor((start + end) / 2);
	tree[level].push_back(arr[mid]);
	recursion(start, mid - 1, level + 1);
	recursion(mid + 1, end, level + 1);
}

int main() {
	cin >> height;
	tree.resize(height);
	int arrSize = pow(2, height) - 1;
	arr.resize(arrSize);
	for (int i = 0; i < arrSize; i++)
		cin >> arr[i];

	recursion(0, arrSize - 1, 0);

	for (auto level : tree) {
		for (int node : level)
			cout << node << ' ';
		cout << '\n';
	}
}