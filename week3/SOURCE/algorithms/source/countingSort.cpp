#include "../header/countingSort.h"

template<class T>
void countingSort(std::vector<T>& array)
{
    T Max = 0;                              
    size_t n = array.size();

    // tìm số lớn nhất trong mảng
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] > Max)
        {
            Max = array[i];                 
        }
    }

    // tạo mảng tần số có chỉ số từ 0 đến số lớn nhất đó
    std::vector<T> frequency(Max + 1, 0);   
    for (size_t i = 0; i < n; i++)
    {
        frequency[array[i]]++;              //đếm tần số với frequency[i] = x thì i là số còn x là tần số của i trong mảng
    }
    for (size_t i = 1; i <= Max; i++)
    {
        frequency[i] += frequency[i - 1];   // tạo mảng cộng dồn từ mảng tần số ban đầu để lấy vị trí cuối cùng của phần tử xuất hiện
    }
    std::vector<T> temp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp[frequency[array[i]] - 1] = array[i];   // duyệt ngược mảng để đưa số ở sau về vị trí đúng (điều làm cho stable)
        frequency[array[i]]--; 
    }

    array = temp;
}

template<class T>
void countingSort(std::vector<T>& array, size_t& count_comparison)
{   
    T Max = 0;                                                 
    size_t n = array.size();

    //tìm số lớn nhất trong mảng
    for (size_t i = 0; ++count_comparison && i < n; i++)
    {
        if (++count_comparison && array[i] > Max)
        {
            Max = array[i];                                      
        }
    }

    // tạo mảng tần số có chỉ số từ 0 đến số lớn nhất đó
    std::vector<T> frequency(Max + 1, 0);                      
    for (size_t i = 0; ++count_comparison && i < n; i++)
    {
        frequency[array[i]]++;                                  // đếm tần số với frequency[i] = x thì i là số còn x là tần số của i trong mảng
    }
    for (size_t i = 1; ++count_comparison && i <= Max; i++)
    {
        frequency[i] += frequency[i - 1];                     // tạo mảng cộng dồn từ mảng tần số ban đầu để lấy vị trí cuối cùng của phần tử xuất hiện
    }
    std::vector<T> temp(n);
    for (int i = n - 1; ++count_comparison && i >= 0; i--)
    {
        temp[frequency[array[i]] - 1] = array[i];              // duyệt ngược mảng để đưa số ở sau về vị trí đúng (điều làm cho stable)
        frequency[array[i]]--;
    }
    array = temp;
}

// INSTANTIATION
//countingSort
template void countingSort(std::vector<int>&);

template void countingSort(std::vector<long long>&);

//countingSort with compare
template void countingSort(std::vector<int>&, size_t&);

template void countingSort(std::vector<long long>&, size_t&);