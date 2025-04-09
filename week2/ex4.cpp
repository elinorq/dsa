#include <iostream>
#include <ctime>
using namespace std;

bool checkPossibleCap(int x, int* a, int n, int d) {
	int sum = 0, count = 0;

		for (int k = 0; k < n; k++) {
			if (x < a[k]) // Nếu x (tải trọng) nhỏ hơn bất kỳ phần tử nào trong mảng, không thể chia được
				return false;
			if (sum + a[k] > x) { // Nếu thêm phần tử hiện tại vào nhóm thì vượt quá x
				sum = 0; // Reset tổng về 0 để bắt đầu chia cho ngày tiếp theo
				k--; 
				count++; // Tăng số ngày đã chia
			}
			else
				sum += a[k]; // Nếu chưa vượt x, tiếp tục thêm vào ngày hiện tại
			if (k < n-1 && count == d)
				return false;

		}
		return true;
}
int main() {
	int n, day;
	cin >> n >> day;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cap = arr[0];
	while (true) {
		bool canShip = checkPossibleCap(cap, arr, n, day);
		
		if (canShip)
			break;
		cap++;

	}
	cout << cap;
	delete[]arr;
	return 0;
}