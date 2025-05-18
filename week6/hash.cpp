#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int SIZE=2000;
const int p = 31;
const int m = 2000;

struct Company{
    string name;
    string profit_tax;
    string address;
};
struct HashTable{
    vector<Company> table[SIZE];
};

vector<Company> readCompanyList(string file_name);
long long hashString(string company_name);
HashTable* createHashTable(vector<Company> list_company);
void insert(HashTable* hash_table, Company company);
Company* search(HashTable* hash_table, string company_name);
void printInfo(Company *c, ofstream &wfile);

vector<Company> readCompanyList(string file_name){
    vector<Company> listComp;
    ifstream rfile(file_name);

    if (!rfile) cout << "Cannot open MST.txt file" << endl;

    string line;
    getline(rfile, line); // Bỏ qua dòng tiêu đề (nếu có)

    while (getline(rfile, line)) {
        stringstream ss(line);
        Company c;
        getline(ss, c.name, '|');
        getline(ss, c.profit_tax, '|');
        getline(ss, c.address);
        listComp.push_back(c);
    }

    return listComp;
}

long long hashString(string company_name){
    string substring = (company_name.size() > 20 ? company_name.substr(company_name.size() - 20) : company_name);
    long long pow = 1;
    long long sum = 0;
    for (size_t i = 0; i<substring.length(); i++){
        sum = (sum + substring[i] * pow)%m;
        pow = (pow * p) % m;
    }
    return sum;
}

//Seperate chaining
HashTable* createHashTable(vector<Company> list_company){
    HashTable *hash = new HashTable;
  
    for (const Company &c : list_company){
        insert(hash, c);
    }
    return hash;
}

void insert(HashTable* hash_table, Company company){
    int index = hashString(company.name);
    hash_table->table[index].push_back(company);
}

Company* search(HashTable* hash_table, string company_name){
    int index = hashString(company_name);
    for (Company &c : hash_table->table[index]){
        if (company_name.compare(c.name) == 0){
            return &c;
        }      
    }
    return nullptr;
}

void printInfo(Company *c, ofstream &wfile){
    if (c){
        cout << c->name << "|"<< c->profit_tax << "|" << c->address << endl;
        wfile << c->name << "|"<< c->profit_tax << "|" << c->address << endl;
    }
    else{
        cout << endl;
        wfile << endl;
    }
}
//4 PP xử lý thì chọn nào cũng được
int main(int argc, char *argv[]) {
    if (argc < 4) return 1;

    ifstream input(argv[2]);
    ofstream output(argv[3]);

    vector<Company> listComp = readCompanyList(argv[1]);

    if (!input) {
        cout << "Cannot open input file" << endl;
        return 1;
    }

    if (!output){
        cout << "Cannot open output file" << endl;
        return 1;
    }

    if (!listComp.empty()) {
        HashTable *htable=createHashTable(listComp);
        
        string line;
        while(getline(input, line)){
            Company *s = search(htable, line);
            printInfo(s, output);
            
        }
        delete htable;
    }
    
    input.close();
    output.close();
    return 0;
}