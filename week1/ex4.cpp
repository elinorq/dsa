#include <iostream>
using namespace std;


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
	// Nếu chỉ có 1 đĩa, di chuyển trực tiếp từ cột nguồn sang cột đích
	if (n == 1) {
		cout << "Move disk 1 from " << from_rod << " to " << to_rod << endl;
		return;
		
	}
	// Di chuyển n-1 đĩa từ cột nguồn sang cột trung gian, sử dụng cột đích làm trung gian
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	// Di chuyển đĩa lớn nhất (đĩa thứ n) từ cột nguồn sang cột đích
	cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
	// Di chuyển n-1 đĩa từ cột trung gian sang cột đích, sử dụng cột nguồn làm trung gian
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	
}

int main() {
	int n;
	cout << "Input the number of disk(s): ";
	cin >> n;
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;

}

