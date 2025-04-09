#include "../header/heapSort.h"

template<class T>
void heapify(std::vector<T>& array, size_t n, size_t i, size_t& count_comparison)
{
    //cài đặt hàm heapify của heapSort
    size_t largest = i;                                    // giả sử cho node cha là lớn nhất
    size_t left = 2 * i + 1;

    if (++count_comparison && left < n && ++count_comparison && array[largest] < array[left])           // tìm node con lớn nhất mà lớn hơn node cha
    {
        largest = left;
    }
    if (++count_comparison && left + 1 < n && ++count_comparison && array[largest] < array[left + 1])
    {
        largest = left + 1;
    }
    if (++count_comparison && largest != i)                                   // nếu node cha không phải lớn nhất thì đổi chỗ sao cho node cha lớn nhất
    {
        swap(array[i], array[largest]);
        heapify(array, n, largest, count_comparison);                       // đệ quy xuống node con ở dưới để node con ở dưới lớn nhất
    }
}

template<class T>
void heapSort(std::vector<T>& array, size_t& count_comparison) 
{
    //cài đặt hàm heapSort
    int n = array.size();
    for (int i = n / 2 - 1; ++count_comparison && i >= 0; i--)                // bắt đầu từ n / 2 - 1 vì đó là phần tử cuối cùng có con
    {
        heapify(array, n, i, count_comparison);                             // xây dựng max heap
    }
    for (int i = n - 1; ++count_comparison && i > 0; i--)
    {
        swap(array[0], array[i]);                           // đổi chỗ phần tử lớn nhất với phần tử phải cùng mà chưa được sắp xếp
        heapify(array, i, 0, count_comparison);                             // heapify tiếp mảng với số phần tử còn lại bắt đầu từ gốc
    }
}

template<class T>
void heapify(std::vector<T>& array, size_t n, size_t i)
{
    //cài đặt hàm heapify của heapSort
    size_t largest = i;                                    // giả sử cho node cha là lớn nhất
    size_t left = 2 * i + 1;
    if (left < n && array[largest] < array[left])           // tìm node con lớn nhất mà lớn hơn node cha
    {
        largest = left;
    }
    if (left + 1 < n && array[largest] < array[left + 1])
    {
        largest = left + 1;
    }
    if (largest != i)                                   // nếu node cha không phải lớn nhất thì đổi chỗ sao cho node cha lớn nhất
    {
        swap(array[i], array[largest]);
        heapify(array, n, largest);                       // đệ quy xuống node con ở dưới để node con ở dưới lớn nhất
    }
}

template<class T>
void heapSort(std::vector<T>& array)
{
    //cài đặt hàm heapSort
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--)                // bắt đầu từ n / 2 - 1 vì đó là phần tử cuối cùng có con
    {
        heapify(array, n, i);                             // xây dựng max heap
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(array[0], array[i]);                           // đổi chỗ phần tử lớn nhất với phần tử phải cùng mà chưa được sắp xếp
        heapify(array, i, 0);                             // heapify tiếp mảng với số phần tử còn lại bắt đầu từ gốc
    }
}

// INSTANTIATION
//heapSort
template void heapify(std::vector<int>&, size_t, size_t);
template void heapSort(std::vector<int>&);

template void heapify(std::vector<long long>&, size_t, size_t);
template void heapSort(std::vector<long long>&);

template void heapify(std::vector<double>&, size_t, size_t);
template void heapSort(std::vector<double>&);

template void heapify(std::vector<float>&, size_t, size_t);
template void heapSort(std::vector<float>&);

template void heapify(std::vector<char>&, size_t, size_t);
template void heapSort(std::vector<char>&);

//heapSort with compare
template void heapify(std::vector<int>&, size_t, size_t, size_t&);
template void heapSort(std::vector<int>&, size_t&);

template void heapify(std::vector<long long>&, size_t, size_t, size_t&);
template void heapSort(std::vector<long long>&, size_t&);

template void heapify(std::vector<double>&, size_t, size_t, size_t&);
template void heapSort(std::vector<double>&, size_t&);

template void heapify(std::vector<float>&, size_t, size_t, size_t&);
template void heapSort(std::vector<float>&, size_t&);

template void heapify(std::vector<char>&, size_t, size_t, size_t&);
template void heapSort(std::vector<char>&, size_t&);