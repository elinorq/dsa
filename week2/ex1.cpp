#include <iostream>
using namespace std;
int linearSearch(int* a, int n, int k) {
	for (int i = 0; i < n; i++) {
		if (a[i] == k)
			return i;
	}
	return -1;
}
int main() {
	int n, k;
	cout << "Input the length of the array: "; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
	cout << "Target: "; cin >> k;

	cout << linearSearch(a, n, k);
	delete[] a;
	return 0;
}