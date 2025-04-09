#include "../header/dataGenerator.h"

//-------------------------------------------------
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

void generateRandomData(std::vector<int> &arr, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
}

void generateSortedData(std::vector<int> &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

void generateReverseData(std::vector<int> &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - 1 - i;
	}
}

void generateNearlySortedData(std::vector<int> &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	srand((unsigned int) time(NULL));
	
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap<int>(arr[r1], arr[r2]);
	}
}

void generateData(std::vector<int> &arr, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	
		generateRandomData(arr, n);
		break;
	case 1:	
		generateNearlySortedData(arr, n);
		break;
	case 2:	
		generateSortedData(arr, n);
		break;
	case 3:	
		generateReverseData(arr, n);
		break;
	default:
		std::cout << "Error: unknown data type!\n";
		break;
	}
}

std::string getDataOrderName(int data_order_id) {
    switch (data_order_id) {
        case 0:
            return "Randomized data";
        case 1:
            return "Nearly sorted data";
        case 2:
            return "Sorted data";
        case 3:
            return "Reverse sorted data";
        default:
            return "Unknown data order";
    }
}

int getDataOrderID(char agr_flag[]) {

    if (!strcmp(agr_flag, "-rand")) return 0;
    else if (!strcmp(agr_flag, "-nsorted")) return 1;
    else if (!strcmp(agr_flag, "-sorted")) return 2;
    else if (!strcmp(agr_flag, "-rev")) return 3;

    return -1;
}