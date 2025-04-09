#include <iostream>
using namespace std;

int rotatedSortedArray(int* a, int n) {
	int left = 0, right = n - 1;
	

	while (left < right) {
		int mid = (left + right) / 2;

		// Nếu phần tử ở mid lớn hơn phần tử cuối cùng, nghĩa là phần tử nhỏ nhất nằm bên phải mid
		if (a[mid] > a[right])
			left = mid + 1;
		else
			right = mid;
	}
	return a[left]; // Khi left == right, ta đã tìm được phần tử nhỏ nhất của mảng

}
int main() {
	int n;
	cout << "Input the length of the array: "; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i	++) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
	

	cout << rotatedSortedArray(a, n);
	delete[] a;
	return 0;
}