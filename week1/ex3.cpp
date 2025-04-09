#include <iostream>
using namespace std;

void generateBinaryStrings(int n, string str) {
    // Điều kiện dừng: khi n = 0, tức là đã tạo đủ độ dài chuỗi
    if (n == 0) {
        cout << str << endl; // In chuỗi nhị phân hiện tại
        return;
    }

    // Gọi đệ quy để thêm '0' vào chuỗi hiện tại
    generateBinaryStrings(n - 1, str + '0');

    // Gọi đệ quy để thêm '1' vào chuỗi hiện tại
    generateBinaryStrings(n - 1, str + '1');
}
int main() {
	int n;
	cout << "Input length: ";
	cin >> n;
    // Gọi hàm để sinh ra tất cả chuỗi nhị phân có độ dài n
	generateBinaryStrings(n, "");

	return 0;
}