#include "../header/helpFunctions.h"
#include "../header/dataGenerator.h"

template <class T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

int random(int l, int r) {
    srand((unsigned int)time(nullptr));
	int ran = rand();
	
	return 1ll * ran % (r - l + 1) + l;
}

bool readData(std::vector<int> &arr, std::string fileName) {
    if (!arr.empty()) {
        arr.clear();
    }

	std::fstream fin(fileName, std::ios::in);

    if (!fin) {
        std::cout << "Error: File not found\n";
        return false;
    }

	int size; fin >> size;
	arr.resize(size);

    for (int i = 0; i < size; i++) {
        fin >> arr[i];
    }

    fin.close();

    return true;
}

bool writeData(std::vector<int> &arr, std::string fileName) {
    std::fstream fout(fileName, std::ios::out);

    if (!fout) {
        std::cout << "Error: File not found\n";
        return false;
    }

	int size = arr.size();
	fout << size << '\n';

    for (int i = 0; i < size; i++) {
        fout << arr[i] << ' ';
    }

	fout.close();

    return true;
}

bool is_number(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }

    return true;
}

int getOutputParameterID(char *param_flag) {
    if (!strcmp(param_flag, "-time")) return 1;
    if (!strcmp(param_flag, "-comp")) return 2;
    if (!strcmp(param_flag, "-both")) return 3;
    return -1;
}

bool isOutputParameterID(char *param_flag) {
    if (getDataOrderID(param_flag) == -1) {
        return true;
    }
    return false;
}

bool isNumber(char *str) {
	int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
	
    return true;
}


template void swap(int&, int&);
template void swap(long long&, long long&);
template void swap(float&, float&);
template void swap(double&, double&);
template void swap(char&, char&);