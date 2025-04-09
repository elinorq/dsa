#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
	if (n == 0 || n == 1) { // Điều kiện dừng: nếu n là 0 hoặc 1 thì trả về chính nó
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2); // Công thức Fibonacci F(n) = F(n-1) + F(n-2)
}

int main() {
	int n;
	
	cout << "Input n: ";
	cin >> n;

	// In ra n số Fibonacci đầu tiên
	for (int i = 0; i < n; i++) {
		cout << fibonacci(i)<< " ";
	}
	return 0;

}
