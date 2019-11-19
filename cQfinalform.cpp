#include <iostream> 

using namespace std;

constexpr auto N = 7;

void inQ(int Q[]) {
	int i;
	for (i = 0; i < N; i++) {
		Q[i] = 0;
	}
}
void printQ(int Q[]) {
	int i;
	for (i = 0; i < N; i++) {
		cout << Q[i] << " ";
	}
	cout << endl;
}
bool isfull(int head, int tail) {
	if (head == tail % N + 1) {
		return true;
	}
	else {
		return false;
	}
}
bool isempty(int head, int tail) {
	if (tail == head) {
		return true;
	}
	else {
		return false;
	}
}
int add(int Q[], int x, int head, int tail) {
	if (isfull(head, tail)) {
		cout << "Queue is full " << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Q[tail] = x;
		tail = (tail + 1) % N;
		return tail;
	}
}
int deQ(int Q[], int head, int tail) {
	if (isempty(head, tail)) {
		cout << " Queue is empty" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Q[head] = 0;
		head = (head + 1) % N;
		return head;
	}
}

int main() {
	int Q[N], i, j;
	int head = 0, tail = 0;
	inQ(Q);
	printQ(Q);
	for (i = 0; i < N-1; i++) {
			tail = add(Q, i + 1, head, tail);
	}
	printQ(Q);
	for (j = 0; j < 3; j++) {
		head = deQ(Q, head, tail);
	}
	printQ(Q);
	
}