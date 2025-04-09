#include "../header/shakerSort.h"

template<class T>
void shakerSort(std::vector<T>& array, size_t& count_comparison) 
{
    //cài đặt hàm shakerSort
    int start = 0;                          // biến giữ vị trí biên trái
    int End = array.size() - 1;                        // biến giữ vị trí biên phải

    // tương tự với Bubble Sort nhưng chạy từ cả 2 phía chưa được sắp xếp
    while (++count_comparison && start <= End)                     
    {
        bool swapped = false;
        // chạy từ bên trái đẩy phần tử lớn nhất lên trên cùng của vị trí chưa được sắp xếp
        for (size_t i = start; ++count_comparison && i < End; i++)    
        {
            if (++count_comparison && array[i] > array[i + 1])
            {
                swapped = true;
                swap<T>(array[i], array[i + 1]);
            }
        }
        End--;
        // chạy từ bên phải đẩy phần tử thấp nhất xuống dưới cùng của vị trí chưa được sắp xếp
        for (int i = End - 1; ++count_comparison && i >= start; i--) 
        {
            if (++count_comparison && array[i] > array[i + 1])
            {
                swapped = true;
                swap<T>(array[i], array[i + 1]);
            }
        }
        if (++count_comparison && !swapped)
        {
            break;
        }
        start++;
    }
}

template<class T>
void shakerSort(std::vector<T>& array) {
    //cài đặt hàm shakerSort
    int start = 0;                          // biến giữ vị trí biên trái
    int End = array.size() - 1;                        //  biến giữ vị trí biên phải

    // tương tự với Bubble Sort nhưng chạy từ cả 2 phía chưa được sắp xếp
    while (start <= End)                     
    {
        bool swapped = false;
        // chạy từ bên trái đẩy phần tử lớn nhất lên trên cùng của vị trí chưa được sắp xếp
        for (size_t i = start; i < End; i++)    
        {
            if (array[i] > array[i + 1])
            {
                swapped = true;
                swap<T>(array[i], array[i + 1]);
            }
        }
        End--;
        // chạy từ bên phải đẩy phần tử thấp nhất xuống dưới cùng của vị trí chưa được sắp xếp
        for (int i = End - 1; i >= start; i--)
        {
            if (array[i] > array[i + 1])
            {
                swapped = true;
                swap<T>(array[i], array[i + 1]);
            }
        }
        if (!swapped) 
        {
            break;
        }
        start++;
    }
}

// INSTANTIATION
//shakerSort
template void shakerSort(std::vector<int>&);
template void shakerSort(std::vector<long long>&);
template void shakerSort(std::vector<double>&);
template void shakerSort(std::vector<float>&);
template void shakerSort(std::vector<char>&);

//shakerSort with compare
template void shakerSort(std::vector<int>&, size_t&);
template void shakerSort(std::vector<long long>&, size_t&);
template void shakerSort(std::vector<double>&, size_t&);
template void shakerSort(std::vector<float>&, size_t&);
template void shakerSort(std::vector<char>&, size_t&);