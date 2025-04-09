
#include "../header/insertionSort.h"

template <class T>
void insertionSort(std::vector<T>& arr, size_t& count_comparison) {
    count_comparison = 0;

    for (size_t i = 1; ++count_comparison && i < arr.size(); ++i) {
        T key = arr[i];
        size_t j = i;

        // dịch chuyển các phần tử arr[0..i-1] lớn hơn key
        while (++count_comparison && j > 0 && ++count_comparison && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key; // đặt key vào vị trí đúng
    }
}

template <class T>
void insertionSort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        size_t j = i;

        // dịch chuyển các phần tử arr[0..i-1] lớn hơn key
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key; // đặt key vào vị trí đúng
    }
}


// INSTANTIATION
//insertionSort with Compare
template void insertionSort(std::vector<int>&, size_t&);
template void insertionSort(std::vector<long long>&, size_t&);
template void insertionSort(std::vector<float>&, size_t&);
template void insertionSort(std::vector<double>&, size_t&);
template void insertionSort(std::vector<char>&, size_t&);

// insertionSort
template void insertionSort(std::vector<int>&);
template void insertionSort(std::vector<long long>&);
template void insertionSort(std::vector<float>&);
template void insertionSort(std::vector<double>&);
template void insertionSort(std::vector<char>&);

