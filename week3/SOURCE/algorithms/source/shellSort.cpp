#include "../header/shellSort.h"

template <class T>
void shellSort(std::vector<T> &arr, size_t &count_comparison) {
    count_comparison = 0;
    size_t n = arr.size();
    
    // khởi đầu với gap bằng n/2 và giảm dần sau mỗi vòng lặp
    for (size_t gap = n / 2; ++count_comparison && gap > 0; gap /= 2) {               

        // thực hiện insertion sort giữa các phần tử cách nhau một đoạn gap
        for (size_t i = gap; ++count_comparison && i < n; ++i) {
            T temp = arr[i];
            size_t j = i;

            // dịch chuyển các phần tử đã sắp xếp lên trên cho đến khi tìm được vị trí thích hợp để chèn
            while (++count_comparison && j >= gap && ++count_comparison && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

template <class T>
void shellSort(std::vector<T> &arr) {
    size_t n = arr.size();

    // khởi đầu với gap bằng n/2 và giảm dần sau mỗi vòng lặp
    for (size_t gap = n / 2; gap > 0; gap /= 2) {

        // thực hiện insertion sort giữa các phần tử cách nhau một đoạn gap
        for (size_t i = gap; i < n; ++i) {
            T temp = arr[i];
            size_t j = i;

            // dịch chuyển các phần tử đã sắp xếp lên trên cho đến khi tìm được vị trí thích hợp để chèn
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// INSTANTIATION
//shellSort with Compare
template void shellSort(std::vector<int>&,  size_t&);
template void shellSort(std::vector<long long>&, size_t&);
template void shellSort(std::vector<float>&, size_t&);
template void shellSort(std::vector<double>&, size_t&);
template void shellSort(std::vector<char>&, size_t&);

// shellSort
template void shellSort(std::vector<int>&);
template void shellSort(std::vector<long long>&);
template void shellSort(std::vector<float>&);
template void shellSort(std::vector<double>&);
template void shellSort(std::vector<char>&);

