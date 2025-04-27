#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct NODE {
	int key;
	NODE* p_next;
};

struct Queue {
	NODE* head;
	NODE* tail;
};

NODE* createNode(int data);
Queue* initializeQueue();
void enqueue(Queue& q, int key);

NODE* createNode(int data) {
	NODE* newNode = new NODE;
	newNode->p_next = nullptr;
	newNode->key = data;
	return newNode;
}

Queue* initializeQueue() {
	Queue* newQueue = new Queue;
	newQueue->head = nullptr;
	newQueue->tail = nullptr;
	return newQueue;
}
void enqueue(Queue& q, int key) {
	NODE* p = createNode(key);
	if (!q.head) {
		q.head = q.tail = p;
	}
	else {
		// Tương tự addTail
		NODE* temp = q.head;
		while (temp->p_next) {
			temp = temp->p_next;
		}
		
		temp->p_next = p;
		q.tail = p;
	}
}
int dequeue(Queue& q) { // Chỉ gọi khi !isEmpty
	if (q.head) { // Tương tự delete head
		NODE* temp = q.head;
		int x = temp->key;
		q.head = q.head->p_next;
		delete temp;
		return x;
	}
}
int size(Queue q) {
	NODE* p = q.head;
	int c = 0;
	while (p) {
		c++;
		p = p->p_next;
	}
	return c;
}
bool isEmpty(Queue q) {
	return (q.head == nullptr);
}
bool isNumber(char c) {
	return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
		|| c == '8' || c == '9');
}


void writeDisplay(Queue q, ofstream& wFile, int a) {
	if (!isEmpty(q)) {
		if (a == 0) {
			NODE* p = q.head;
			while (p) {
				wFile << p->key << " ";
				p = p->p_next;
			}
		}
		else if (a == 1)
			wFile << size(q);
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
		Queue* q = nullptr;
		int a = 0;  //Dùng để kiểm soát lúc in ra output, a = 0 thì in ra trong queue, a = 1 in ra size
		while (getline(rFile, line)) {
			a = 0;
			if (line == "init") {
				q = initializeQueue();
			}
			else if (line == "dequeue" && q) {
				if (!isEmpty(*q)) {
					dequeue(*q);
				}
			}
			else if (line.find("enqueue")  ==0 && q) {
				char c;
				string num;
				for (char c : line) {
					if (isNumber(c))
						num += c;
				}
				int x = stoi(num);
				enqueue(*q, x);


			}
			else if (line == "size" && q) {
				a = 1;
			}
			else if (!q) {
				wFile << "Queue isn't initialized!";
				break;
			}
			writeDisplay(*q, wFile, a);
			wFile << endl;
		}
	}
	rFile.close();
	wFile.close();
	return 0;
}