#include <iostream> 
#include <ctime>
using namespace std;

struct node {
	int key;
	struct node *right, *left;
};

struct node* newnode(int item) {
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int key) {
	if (node == NULL) {
		return newnode(key);
	} 
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	return node;
}
struct node* min(struct node* root) {
	struct node* temp = root;
	while (temp && temp -> left != NULL) {
		temp = temp->left;
	}
	return temp;
}
struct node* deletion(struct node* node, int key) {
	if (node == NULL) {
		return node;
	}
	if (key < node->key) {
		node->left = deletion(node->left, key);
	}
	else if (key > node->key) {
		node->right = deletion(node->right, key);
	}
	else {
		if (node->left == NULL) {
			struct node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			struct node* temp = node->left;
			free(node);
			return temp;
		}
		struct node* temp = min(node);
		node->key = temp->key;
		deletion(node->right, temp->key);
	}
	return node;
}
void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high) {
	int j, i = low;
	for (j = low; j < high; j++)
	{
		if (arr[j] <= arr[low]) 
		{
			swap(arr[j], arr[i]);
			i++;
		}
	}
	swap(arr[i - 1], arr[low]);
	return i;
}
void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int part = partition(arr, low, high);
		quicksort(arr, low, part - 1);
		quicksort(arr, part + 1, high);
	}
}
void inorder(struct node* temp) {
	if (temp != NULL) {
		inorder(temp->left);
		cout << temp->key << " ";
		inorder(temp->right);
	}
}
void print(int arr[]) {
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	struct node* root = NULL;
	int size = 20;
	int chosen;
	int* arr = (int*)malloc(size * sizeof(int));
	srand(time(0));
	root = insert(root, 50);
	for (int i = 0; i < 20; i++) {
		int j = rand() % 100 + 1;
		arr[i] = j;
		insert(root, j);
	}
	quicksort(arr, 0, size);
	print(arr);
	inorder(root);
	cout << "\nchosen key to delete (enter key value): " << endl;
	cin >> chosen;
	deletion(root, chosen);
	cout << "\nupdated binary tree: " << endl;
	inorder(root);
	system("pause");
	return 0;
}
