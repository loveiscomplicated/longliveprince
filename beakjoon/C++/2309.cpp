#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		sum += a;
		arr.push_back(a);
	}

	int a = 0;
	int b = 0;

	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				a = i;
				b = j;
			}
		}
	}

	arr.erase(arr.begin() + a);
	arr.erase(arr.begin() + b);
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	return 0;
}