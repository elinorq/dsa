#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct Stack {
	NODE* top;
};


NODE* createNode(int data);
Stack* initializeStack();
void push(Stack& s, int key);
int pop(Stack& s);



NODE* createNode(int data) {
	NODE* newNode = new NODE;
	newNode->p_next = nullptr;
	newNode->key = data;
	return newNode;
}

Stack* initializeStack() {
	Stack *newStack = new Stack;
	newStack->top = nullptr;
	return newStack;
}

void push(Stack& s, int key) {
	NODE* q = createNode(key);
	q->p_next = s.top;
	s.top = q;
	
}
int pop(Stack& s) {
	if (s.top) {
		NODE* temp = s.top;
		int x = s.top->key;
		s.top = s.top->p_next;
		delete temp;
		return x;
	}
}
int size(Stack s) {
	NODE* q = s.top;
	int c = 0;
	while (q) {
		c++;
		q = q->p_next;
	}
	return c;
}
bool isEmpty(Stack s) {
	return (s.top == nullptr);
}

bool isNumber(char c) {
	return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
		|| c == '8' || c == '9');
}

void writeFromBottom(NODE*q, ofstream& wFile) {
	if (!q)
		return;
	writeFromBottom(q->p_next, wFile);
	wFile << q->key << " ";
}
void writeDisplay(Stack s, ofstream& wFile, int a) {
	if (!isEmpty(s)) {
		if (a == 0) {
		NODE* q = s.top;
			writeFromBottom(q, wFile);
		}
		else if (a == 1) {
			wFile << size(s);
		}
	}
	else
		wFile << "EMPTY";

}
int main() {
	ifstream rFile("input.txt");
	ofstream wFile("output.txt");
	if (!rFile)
		cout << "Cannot find input file";
	else {
		string line;
		Stack* s = nullptr;
		int a = 0; //Dùng để kiểm soát lúc in ra output, a = 0 thì in ra trong stack, a = 1 in ra size
		while (getline(rFile, line)) {
			a = 0;
			if (line == "init") {
				s = initializeStack();
			}
			else if (line == "pop" && s) {
				if (!isEmpty(*s)) {
					pop(*s);
				}
			}
			else if (line.find("push") == 0 && s) {
				char c;
				string num;
				for (char c : line) {
					if (isNumber(c))
						num += c;
				}
				int x = stoi(num);
				push(*s, x);
			}
			else if (line == "size" && s)
				a = 1;
			else if (!s) {
				wFile << "Stack isn't initialized!";
				break;
			}
			writeDisplay(*s, wFile, a);
			wFile << endl;
		}
	}
	rFile.close();
	wFile.close();
	return 0;
}