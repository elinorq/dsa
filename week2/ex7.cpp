#include <iostream>
using namespace std;

void merge(int* a, int left, int right, int mid) {
	int i = left, j = mid + 1, k=0;
	int* temp = new int[right - left + 1];

	while (i <= mid && j <= right) {
		if (a[i] > a[j])
			temp[k++] = a[j++];
		else
			temp[k++] = a[i++];
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= right) {
		temp[k++] = a[j++];
	}
	for (int x = 0; x < k; x++) {
		a[left + x] = temp[x];
	}
	delete[]temp;
}
void mergeSort(int* a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;


		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);

		merge(a, left, right, mid);
	}
}
bool twoSum(int* a, int n, int target) {
	int *left = a, *right = a+n-1;
	while (left < right) {
		if (*left + *right > target)
			right--;
		else if (*left + *right < target)
			left++;
		else {
			cout << -target << " " << *left << " " << *right << " " << endl;
			return true;
		}
	}
	return false;
}
void triplets(int* a, int n) { 
	// Sắp xếp mảng thành một dãy tăng để tận dụng two pointers
	mergeSort(a, 0, n-1);

	// Lấy phần tử a[i] làm target, tìm trong mảng còn lại xem có hai phần tử nào tổng bằng -a[i] hay không
	for (int i = 0; i < n; i++) {
		twoSum(a + 1 + i, n - i - 1, -a[i]);
			
	}
	

}
int main() { //Dưới n^2 là không thể
	int n;
	cout << "Input the length of the array: "; cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	triplets(a, n);
	delete[]a;
	return 0;
}