#include <iostream>
using namespace std;
bool twoSum(int* a, int n, int target) {
	int* left = a, * right = a+n-1, sum = 0;
	while (left < a+n && left <= right) {
		if (*left + *right < target)
			left++;
		else if (*left + *right < target)
			right--;
		else
			return true;
	}
	return false;
}
int main() {
	int n, target;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> target;
	if (twoSum(a, n, target))
		cout << "YES";
	else
		cout << "NO";
		delete[]a;
	return 0;
}