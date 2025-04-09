#include "../header/flashSort.h"

template <class T> 
void flashSort(std::vector<T> &arr, size_t &count_comparison) {
    if (++count_comparison && (arr.size() <= 1)) return;

	int min_arr = arr[0], max_arr = arr[0];
	double alpha = 0.45;

	// tìm min và max trong mảng

	for (int i = 1;++count_comparison && (i < arr.size()); i++) {
		if (++count_comparison && (arr[i] < min_arr)) {
			min_arr = arr[i];
		}
		else if (++count_comparison && (arr[i] > max_arr)) {
			max_arr = arr[i];
		}
	}

	if (++count_comparison && (max_arr == min_arr))
		return;

	int m = arr.size() * alpha; 

	// đảm bảo có ít nhất 2 lớp

	if (++count_comparison && (m <= 2)) m = 2;
	
	std::vector<int> L(m, 0);

	// đếm số phần tử trong từng lớp

	for (int i = 0; ++count_comparison && (i < arr.size()); i++) {
		int k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		L[k]++;
	}

	// prefix sum để tìm vị trí bắt đầu của mỗi lớp trong mảng
	for (int k = 1;++count_comparison && (k < m); k++) L[k] += L[k - 1];	

	int i = 0;
	int count = 0;
	int k = m - 1;

	// đưa các phần tử về đúng lớp
	while (++count_comparison && (count < arr.size())) {
		while (++count_comparison && (i >= L[k])) {
			i++;
			k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		}

		int flash = arr[i];
		while (++count_comparison && (i != L[k])) {
			k = 1ll * (m - 1) * (flash - min_arr) / (max_arr - min_arr);
			swap(arr[L[k] - 1], flash);

			L[k]--;
			count++;
		}
	}
	// thực hiện insertion sort để sắp xếp từng lớp
	for (int k = 1;++count_comparison && (k < m); k++) {
		int selected = 0, j = 0;

		for (int i = L[k - 1] + 1;++count_comparison && (i < L[k]); i++) {
			selected = arr[i];
			j = i - 1;
	
			// đặt phần tử đã chọn vào đúng vị trí trong lớp
			while (++count_comparison && (j >= 0) &&++count_comparison && (arr[j] > selected)) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = selected;
		}
	}

	return;
}

template <class T> void flashSort(std::vector<T> &arr) {
    if (arr.size() <= 1) return;

	int min_arr = arr[0], max_arr = arr[0];
	double alpha = 0.45;

	// tìm min và max trong mảng

	for (int i = 1;i < arr.size(); i++) {
		if (arr[i] < min_arr)
			min_arr = arr[i];
		else if (arr[i] > max_arr)
			max_arr = arr[i];
	}

	if (max_arr == min_arr)
		return;

	int m = arr.size() * alpha;

	// đảm bảo có ít nhất 2 lớp
	if (m <= 2) m = 2;

    std::vector<int> L(m, 0);

	for (int i = 0; i < arr.size(); i++) {
		int k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		L[k]++;
	}

	// prefix sum để tìm vị trí bắt đầu của mỗi lớp trong mảng

	for (int k = 1; k < m; k++) L[k] += L[k - 1];
	
	int i = 0;
	int count = 0;
	int k = m - 1;

	// đưa các phần tử về đúng lớp

	while (count < arr.size()) {
		while (i >= L[k]) {
			i++;
			k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		}

		int flash = arr[i];
		while (i != L[k]) {
			k = 1ll * (m - 1) * (flash - min_arr) / (max_arr - min_arr);

			swap(arr[L[k] - 1], flash);
			L[k]--;
			count++;
		}
	}

	// thực hiện insertion sort trong mỗi lớp

	for (int k = 1; k < m; k++) {
		int selected = 0, j = 0;

		for (int i = L[k - 1] + 1; i < L[k]; i++) {
			selected = arr[i];
			j = i - 1;
	
			// đặt phần tử đã chọn vào đúng vị trí trong lớp
			while ((j >= 0) && (arr[j] > selected)) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = selected;
		}
	}

	return;
}

template void flashSort(std::vector<int> &arr, size_t &count_comparison);
template void flashSort(std::vector<int> &arr);