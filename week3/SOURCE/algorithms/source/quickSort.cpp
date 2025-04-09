#include "../header/quickSort.h"

template<class T>
int Partition(std::vector<T>& array, int low, int high, size_t& count_comparison)   // sử dụng cải tiến với lấy pivot là trung vị của 3 số array[low], array[high] và array[mid]
{
    int mid = low + (high - low) / 2;
    T pivot = array[mid];
    int index_pivot = mid;

    // phần tử pivot là phần tử trung vị của array[low], array[high] và array[mid]
    if (++count_comparison && pivot > array[low] && ++count_comparison && pivot > array[high])  
    {
        if (++count_comparison && array[low] > array[high])
        {
            pivot = array[low];
            index_pivot = low;
        }
        else 
        {
            pivot = array[high];
            index_pivot = high;
        }
    }
    else 
    {
        if (++count_comparison && pivot < array[low] && ++count_comparison && pivot < array[high])
        {
            if (++count_comparison && array[low] < array[high])
            {
                pivot = array[low];
                index_pivot = low;
            }
            else 
            {
                pivot = array[high];
                index_pivot = high;
            }
        }
    }
    int i = low - 1;

    // hoán vị pivot và phần tử cuối (high)
    T temp = array[high];
    array[high] = array[index_pivot];
    array[index_pivot] = temp;

    pivot = array[high];
    index_pivot = high;
   
    // tìm vị trí thích hợp cho pivot
    for (int j = low; ++count_comparison && j <= high - 1; j++)        
    {
        if (++count_comparison && array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    // đưa pivot về đúng vị trí
    swap(array[i + 1], array[high]);                     
    return i + 1;
}

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high, size_t& count_comparison)
{
    if (++count_comparison && low < high)
    {
        int par = Partition(array, low, high, count_comparison);        //tìm pivot
        impleQuickSort(array, low, par - 1, count_comparison);          //thực hiện quickSort ở bên trái pivot
        impleQuickSort(array, par + 1, high, count_comparison);         //thực hiện quickSort ở bên phải pivot
    }
}

template<class T>
void quickSort(std::vector<T>& array, size_t& count_comparison) 
{
    impleQuickSort(array, 0, array.size() - 1, count_comparison);       
}

template<class T>
int Partition(std::vector<T>& array, int low, int high) //sử dụng cải tiến với lấy pivot là trung vị của 3 số array[low], array[high] và array[mid]
{
    int mid = low + (high - low) / 2;
    T pivot = array[mid];
    int index_pivot = mid;

    //phần tử pivot là phần tử trung vị của array[low], array[high] và array[mid]
    if (pivot > array[low] && pivot > array[high])      
    {
        if (array[low] > array[high])
        {
            pivot = array[low];
            index_pivot = low;
        }
        else 
        {
            pivot = array[high];
            index_pivot = high;
        }
    }
    else 
    {
        if (pivot < array[low] && pivot < array[high])
        {
            if (array[low] < array[high])
            {
                pivot = array[low];
                index_pivot = low;
            }
            else 
            {
                pivot = array[high];
                index_pivot = high;
            }
        }
    }
    int i = low - 1;

    // hoán vị pivot và phần tử cuối (high)
    T temp = array[high];
    array[high] = array[index_pivot];
    array[index_pivot] = temp;
    
    pivot = array[high];
    index_pivot = high;

    //tìm vị trí của phần tử pivot
    for (int j = low; j <= high - 1; j++)               
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    //đưa pivot về đúng vị trí
    swap(array[i + 1], array[high]);
    return i + 1;
}

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high)
{
    if (low < high)
    {
        int par = Partition(array, low, high);          //tìm pivot
        impleQuickSort(array, low, par - 1);            //thực hiện quickSort ở bên trái pivot
        impleQuickSort(array, par + 1, high);           //thực hiện quickSort ở bên phải pivot
    }
}

template<class T>
void quickSort(std::vector<T>& array) 
{
    impleQuickSort(array, 0, array.size() - 1);
}

// INSTANTIATION
//quickSort
template int Partition(std::vector<int>&, int, int);
template void impleQuickSort(std::vector<int>&, int, int);
template void quickSort(std::vector<int>&);

template int Partition(std::vector<long long>&, int, int);
template void impleQuickSort(std::vector<long long>&, int, int);
template void quickSort(std::vector<long long>&);

template int Partition(std::vector<double>&, int, int);
template void impleQuickSort(std::vector<double>&, int, int);
template void quickSort(std::vector<double>&);

template int Partition(std::vector<float>&, int, int);
template void impleQuickSort(std::vector<float>&, int, int);
template void quickSort(std::vector<float>&);

template int Partition(std::vector<char>&, int, int);
template void impleQuickSort(std::vector<char>&, int, int);
template void quickSort(std::vector<char>&);

//quickSort with compare
template int Partition(std::vector<int>&, int, int, size_t&);
template void impleQuickSort(std::vector<int>&, int, int, size_t&);
template void quickSort(std::vector<int>&, size_t&);

template int Partition(std::vector<long long>&, int, int, size_t&);
template void impleQuickSort(std::vector<long long>&, int, int, size_t&);
template void quickSort(std::vector<long long>&, size_t&);

template int Partition(std::vector<double>&, int, int, size_t&);
template void impleQuickSort(std::vector<double>&, int, int, size_t&);
template void quickSort(std::vector<double>&, size_t&);

template int Partition(std::vector<float>&, int, int, size_t&);
template void impleQuickSort(std::vector<float>&, int, int, size_t&);
template void quickSort(std::vector<float>&, size_t&);

template int Partition(std::vector<char>&, int, int, size_t&);
template void impleQuickSort(std::vector<char>&, int, int, size_t&);
template void quickSort(std::vector<char>&, size_t&);