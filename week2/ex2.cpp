#include <iostream>
using namespace std;
int sentinellinearSearch(int* a, int n, int k) {
	int temp = a[n - 1];
	a[n - 1] = k;
	int i = 0;
	while (a[i] != k)
		i++;
	
	a[n - 1] = temp;
	if (i < n - 1 || a[n - 1] == k)
		return i;
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

	cout << sentinellinearSearch(a, n, k);
	delete[] a;
	return 0;
}