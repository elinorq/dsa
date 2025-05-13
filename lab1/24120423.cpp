#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

//struct BigInt
struct BigInt {
    bool isNegative = false;
    string digits;
    BigInt(const string& s) {
        string input = s;
        if (!s.empty() && s[0] == '-') {
            isNegative = true;
            input = s.substr(1);
        }
        digits = input;
        std::reverse(digits.begin(), digits.end());
        normalize();
    }
    BigInt(int num) {
        if (num < 0) isNegative = true;
        digits = to_string(num);
        reverse(digits.begin(), digits.end());
        normalize();
    }
    void normalize() {
        while (digits.size() > 1 && digits.back() == '0') {
            digits.pop_back();
        }
        if (digits == "0")
            isNegative = false;
    }
};

// Prototype
BigInt addTwoInt(const BigInt &a, const BigInt &b);
BigInt subtractTwoInt(BigInt a, BigInt b);
BigInt multiplyTwoInt(const BigInt &a, const BigInt &b);
BigInt divideTwoInt(BigInt a, BigInt b);

bool isOperator(char &c);
bool sameOp(const BigInt &a, const BigInt &b);
int compare(const BigInt &a, const BigInt &b);
void reverseDigits(BigInt &a);
int compare(const BigInt &a, const BigInt &b);
bool precedenceOperator(char &top, char &c);
void removeSpaces(string& s);
bool isUnaryMinus(int i, string& s);
string getIntString(char *start, char *&end);
string infixToPostfix(string &line);
BigInt calc(string &s);
void writeResult(BigInt &r, ofstream &wFile);
bool isProperPostfix(string& s);

//Definition
bool isOperator(char &c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool sameOp(const BigInt &a, const BigInt &b){
    return (a.isNegative == b.isNegative);
}
int compare(const BigInt &a, const BigInt &b) {
    const int lna = static_cast<int>(a.digits.length());
    const int lnb = static_cast<int>(b.digits.length());
    
    if (lna != lnb) {
        return (lna < lnb) ? -1 : 1;
    }
    
    for (int i = lna - 1; i >= 0; --i) {
        if (a.digits[i] != b.digits[i]) {
            return (a.digits[i] < b.digits[i]) ? -1 : 1;
        }
    }
    
    return 0;
}
void reverseDigits(BigInt &a){
    reverse(a.digits.begin(), a.digits.end());
}
bool precedenceOperator(char &top, char &c){
    if (isOperator(top) && isOperator(c)){
        int prior_1= -1, prior_2=-1;
        switch(top){
            case '+': case '-': prior_1 = 0; break;
            case '*': case '/': prior_1 = 1; break;
        }
        switch(c){
            case '+': case '-': prior_2 = 0; break;
            case '*': case '/': prior_2 = 1; break;
        }
        return (prior_1 >= prior_2);
    }
    return false;
}
void removeSpaces(string& s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
}
bool isUnaryMinus(int i, string &s) {
    if (s[i] == '-' && i > 0) {
        return s[i - 1] == '(';
    }
    return false;

}
// Calculation
BigInt addTwoInt(const BigInt &a, const BigInt &b){
    BigInt result("");

    int lna = static_cast<int>(a.digits.length()), lnb = static_cast<int>(b.digits.length());
    int n = max(lna, lnb);
    int carry = 0;
    
    for(int i =0; i<n;i++){
            
        int digitA = (i<lna ? a.digits[i] - '0' : 0);
        int digitB = (i<lnb ? b.digits[i] - '0' : 0);
        int temp = digitA + digitB + carry;
            
        result.digits.push_back((temp%10) +'0');
        carry = temp/10;

    }
    if (carry)
        result.digits.push_back(carry + '0');
        
    result.normalize();
    result.isNegative = a.isNegative;
    
    return result;
}
BigInt subtractTwoInt(BigInt a, BigInt b){
    BigInt result("");
    bool negative = a.isNegative;
    if (compare(a,b) == -1){ 
        negative = !negative;
        swap(a,b);
    }
    int lna = static_cast<int>(a.digits.length()),  lnb = static_cast<int>(b.digits.length());

    int  borrow =0;
    for (int i = 0; i<lna; i++){
        int digitA = a.digits[i] -'0';
        int digitB = (i<lnb ? b.digits[i] - '0' : 0);
        
        int temp = digitA - digitB - borrow;
        if(temp < 0){
            temp += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        result.digits.push_back(abs(temp)%10 + '0');
        
    }
    result.normalize();
    result.isNegative = negative;

    
    return result;
}
BigInt multiplyTwoInt(const BigInt &a, const BigInt &b){
    BigInt result("");
    int lna = static_cast<int>(a.digits.length()), lnb = static_cast<int>(b.digits.length());
    stack<BigInt> operand;

    for (int i = 0; i < lna; i++){
        BigInt x("");
        x.digits=string(i, '0'); //Dịch i phần tử sang trái
        int carry = 0;
        int digitA = (i < lna ? a.digits[i] - '0' : 0);
        for (int j =0; j<lnb; j++){    
            int digitB = (j < lnb ? b.digits[j] - '0' : 0);
            int temp = digitA*digitB + carry;
            x.digits.push_back(temp%10 + '0');
            carry = temp/10;
        
        }    
        if (carry){
            x.digits.push_back(carry + '0');
            carry= 0;
        }

        operand.push(x);
    }
    // Cộng tất cả trong operand
    while (operand.size()>1){
        BigInt m = operand.top(); operand.pop();
        BigInt n = operand.top(); operand.pop();
        result = addTwoInt(m,n);
        operand.push(result);
    }
    if (!operand.empty())   
        result = operand.top();

    result.normalize();
    result.isNegative = !sameOp(a,b);

   
    return result;
}
BigInt divideTwoInt(BigInt a, BigInt b){
    BigInt result("");
    if (b.digits == "0")
        return result;
    int cmp = compare(a,b);
    if (cmp <= 0){
        switch(cmp){
        case -1: result.digits.push_back('0'); break;
        case 0: result.digits.push_back('1'); break;
        }
    }
    else{
        BigInt remainder("");
        int lna = static_cast<int>(a.digits.length());
        for (int i = lna - 1; i >= 0; i--) {
            remainder.digits.insert(remainder.digits.begin(), a.digits[i]);
            int x = 0;
            remainder.normalize();
        
            while (compare(remainder, b) >= 0){
             
                remainder = subtractTwoInt(remainder, b);
                x++;
            }
        
        
        result.digits.append(to_string(x));
        }
        
        reverseDigits(result);
        result.normalize();

        
    }
    result.isNegative = !sameOp(a, b);

    return result;
}

// Processing expressions
string getIntString(char *start, char *&end){
    // Space delimiter
    string num="";
    char* ptr = start;
    if (*ptr == '-') {
        num.push_back(*ptr);
        ptr++;
    }
    while (ptr && isdigit(*ptr))
        ptr++;

    if (ptr) end = ptr;
    num.assign(start, end);
    return num;
}
string infixToPostfix(string &line){
        stack<char> op;
        string postfix ="";
        bool minus = false;
        for (int i = 0; i < line.length(); i++) { 
            if (isdigit(line[i])){ 
                char* start = &line[i], * end = nullptr;
                string num = getIntString(start, end);
                postfix += num + " ";
                i += end - start - 1; //Skip qua đoạn số
            }
            else if (line[i] == '(') {
                op.push(line[i]);
            }
            else if (line[i] == ')') {
                bool foundOpening = false;
                while (!op.empty()) {
                    if (op.top() != '(') {
                        char temp = op.top();
                        op.pop();
                        postfix += string(1, temp) + " ";
                    }
                    else {
                        foundOpening = true;
                        op.pop(); //Remove '(' or do nothing if empty
                        break;
                    }
                }

                if (!foundOpening) {
                    postfix += ") "; // Thêm ngoặc dư vào postfix để tiện tìm lỗi
                } 
            }
            else if (isOperator(line[i])) {
                if ((line[i] == '-' && isUnaryMinus(i, line) && i + 1 < line.size())) {
                    // Kiểm tra xem số có bọc trong ngoặc hay không
                    int j = i + 1;
                    int parenDepth = 0;

                    // Duyệt qua biểu thức bên trong ngoặc
                    while (j < line.size()) {
                        if (line[j] == '(') {
                            parenDepth++;
                        } else if (line[j] == ')') {
                            if (parenDepth == 0)
                                break;
                            parenDepth--;
                        }
                        j++;
                    }

                    // Nếu j vẫn trong phạm vi và ký tự là ')', nghĩa là toàn bộ biểu thức đã khép ngoặc
                    if (j < line.size() && line[j] == ')') {
                        postfix += "0 ";
                    }
                    else{
                        postfix += "! "; //Flag error
                    }
                }
                        // stack isnt empty, stack top >= ch, top isnt '('
                while (!op.empty() && (op.top() != '(') && precedenceOperator(op.top(), line[i])) {
                    char temp = op.top();
                    op.pop();
                    postfix += string(1, temp) + " ";
                }
                op.push(line[i]);
            }
            else{
                return "";
            }
            }
            while (!op.empty()) {
                postfix += string(1, op.top()) + " ";
                op.pop();
            }
            return postfix;
        }
BigInt calc(string &s){
    //postFix exp: 324328 13144 890 / -
    stack<BigInt> operand;
    for (int i = 0; i < s.length() ;i++){
        if (isdigit(s[i])){
            char *start = &s[i], *end=start;
            string num = getIntString(start, end);
            BigInt temp(num);
            operand.push(temp);
            i += end - start-1;
        }
        else if (isOperator(s[i])){
            BigInt a = operand.top(); operand.pop();
            BigInt b = operand.top(); operand.pop();
            BigInt result("");
            if (a.digits == "0" && s[i] == '/'){
                operand.push(result);
                break;
            }
            switch (s[i]) {
            case '+': if (sameOp(a, b)) { result = addTwoInt(b,a); }
                    else { result = subtractTwoInt(b, a); } break;
            case '-': if (sameOp(a, b)) { result = subtractTwoInt(b, a); }
                    else { result = addTwoInt(b, a);  }break;
            case '*': result = multiplyTwoInt(b,a); break;
            case '/': result = divideTwoInt(b, a); break;
            }

            if (result.digits == "0") result.isNegative = false;
            operand.push(result);
        }
    }
    return operand.top();
}
void writeResult(BigInt &r, ofstream &wFile) {
    if (r.digits == ""){
        wFile << "Error" << endl;
        cout << "Error" << endl;
    }
    else{
        reverse(r.digits.begin(), r.digits.end());
        if (r.isNegative) {
            wFile << "-";
            cout << "-";
        }
        wFile << r.digits << endl;
        cout << r.digits << endl;
    }
}
bool isProperPostfix(string& s) {
    if (s.empty() || s == "") return false;
    stack<string> operand;
    int countOperator = 0, countOpenParenthese =0, countCloseParenthese =0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (isdigit(s[i]) || (s[i] == '-' && i + 1 < s.size() && isdigit(s[i + 1]))) {
                char* start = &s[i], * end = start;
                string num = getIntString(start, end);
                operand.push(num);
                i += end - start - 1;
            }
            // Chia không
            else if (s[i] == '/' && operand.top() == "0") {
                return false;
            }
            else if (s[i] == '(') {
                countOpenParenthese++;
            }
            else if (s[i] == ')') {
                countCloseParenthese++;
            }
            else if (isOperator(s[i])) {
                countOperator++;
                if (countOperator >= operand.size()) { //Tại thời điểm xét toán tử, so sánh với số toán hạng đã nạp vào stack
                    return false;
                }
            }
        }
    }

    if (countOpenParenthese != 0 && countCloseParenthese != 0) {
        return false;
    }
    if (countOpenParenthese == 0 && countCloseParenthese != 0) {
        return false;
    }
    if (countOpenParenthese != 0 && countCloseParenthese == 0) {
        return false;
    }
    return true;
    
}

int main(int argc, char *argv[]){
    if (argc < 3) return 1;

    ifstream rFile(argv[1]);
    ofstream wFile(argv[2]);
    
    if (!rFile) cout << "Khong the mo file " << argv[1];
    if (!wFile) cout << "Khong the mo file " << argv[2];
    
    if (rFile.is_open() || wFile.is_open()){
        
        string line;
        BigInt result("");
        while (getline(rFile, line)){
            if (!line.empty()){
                removeSpaces(line);
                line = infixToPostfix(line);
                if (!isProperPostfix(line)) {
                    wFile << "Error" << endl;
                    cout << "Error" << endl;
                }
                else {
                    result = calc(line);
                    writeResult(result, wFile);
                }
            }
        }
    }
    rFile.close();
    wFile.close();
    return 0;
}
