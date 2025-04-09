#include <iostream>
using namespace std;

const int N = 8; // Kích thước bàn cờ NxN
int board[N][N] = { 0 }; // Lưu vị trí các quân hậu trên bàn cờ
int solutions = 0; // Đếm số nghiệm thỏa


bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false; // Kiểm tra cột
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
            return false; // Kiểm tra đường chéo trên trái
        if (col + (row - i) < N && board[i][col + (row - i)] == 1)
            return false; // Kiểm tra đường chéo trên phải
        }
        
    return true;

}


void placeQueens(int row, int col) {
    if (row == N) { // Nếu đã đặt đủ N quân hậu
        solutions++;
        return;
    }

    if (col >= N)
        return; // Dừng lại nếu vượt khỏi bàn cờ

    if (isSafe(row, col)) {
        board[row][col] = 1; // Đặt quân hậu
        placeQueens(row + 1, 0); // Sang dòng tiếp theo, bắt đầu từ cột 0
        board[row][col] = 0; // Quay lui
    }

    placeQueens(row, col + 1); // Thử đặt ở cột tiếp theo
}


int main() {
    placeQueens(0, 0);
    cout << solutions << endl;
    return 0;
}
