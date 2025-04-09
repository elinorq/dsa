#include <iostream>
using namespace std;

int fintMinimalSubArr(int* a, int n, int target) {

	int* left = a, * right = a, sum = a[0], minLength = INT_MAX;
	while (right < a+n) {
		if (sum < target) { // Nếu tổng nhỏ hơn `target`, mở rộng cửa sổ sang phải
			right++;
			if (right < a+ n)
				sum += *right;
		}
		else { // Nếu tổng >= `target`, kiểm tra độ dài cửa sổ và thu hẹp cửa sổ từ trái
			if (minLength > right - left + 1)
				minLength = right - left + 1;

			sum -= *left; // Loại bỏ phần tử bên trái khỏi tổng
			left++;
			if (left > right)
				break;
		}
	}

	return (minLength != INT_MAX) ? minLength : 0; // Nếu không tìm thấy mảng con phù hợp, trả về 0
}

int main() {
	int n, target;
	cout << "Input the length of array: "; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
			
		cin >> a[i];
	}
	cout << "Input target: "; cin >> target;
	cout << fintMinimalSubArr(a, n, target);
	delete[]a;

	return 0;
}