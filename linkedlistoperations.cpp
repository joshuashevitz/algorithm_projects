#include <iostream> 
using namespace std;

struct node {
	int data;
	node* next;
};

class linked {

private:
	node* head;
	node* tail;
public: 
	linked() {
		head = NULL;
		tail = NULL;
	}
	node* gethead() {
		return head;
	}
	void create(int n) {
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	void display() {
		node* temp;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << " "; 
			temp = temp->next;
		}
	}
	void createathead(int n) {
		node* temp = new node;
		temp->data = n;
		temp->next = head;
		head = temp;
	}
	void deletion(node* head, int position) {
		node* temp;
		node* current;
		current = head;
		temp = current->next;
		if (position == 0) {
			head = current->next;
			delete current;

		}
		while (temp->data != position) {
			current = current->next;
			temp = temp->next;
		}
		current->next = temp->next;
		delete temp;
	}
};

int main() {
	linked list; 
	list.create(2);
	list.create(3);
	list.display();
	cout << endl;
	list.createathead(1);
	list.display();
	list.deletion(list.gethead(), 2);
	cout << endl;
	list.display();
}