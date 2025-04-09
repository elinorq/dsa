#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của một số nguyên n
int factorial(int n) {
	if (n == 0 || n == 1) // Điều kiện dừng: nếu n = 0 hoặc n = 1 thì trả về 1
		return 1;
	return n * factorial(n - 1); // Công thức giai thừa: n! = n * (n-1)!
}

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	// In ra giai thừa của số n
	cout << factorial(n);
	return 0;
}