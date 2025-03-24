#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
	// Nếu mảng chỉ có 0 hoặc 1 phần tử thì chắc chắn được sắp xếp
	if (n == 1 || n == 0)
		return true;

	// Nếu phần tử đầu tiên lớn hơn phần tử kế tiếp, mảng không được sắp xếp
	if (arr[0] > arr[1])
		return false;

	// Kiểm tra phần còn lại của mảng bằng cách gọi đệ quy với phần tử tiếp theo
	return isSorted(arr + 1, n - 1);
}

int main() {
	int n;
	cout << "Input the length of the array: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
	if (isSorted(arr, n))
		cout << "The array is sorted.\n";
	else
		cout << "The array is NOT sorted.\n";
	
	return 0;

}
