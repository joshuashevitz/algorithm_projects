#include <iostream> 

using namespace std;

struct node {
	int data;
	node* parent;
	node* left;
	node* right;
};

typedef nodepointer;

class BST {
private:
	nodepointer root;

	void initialize(nodepointer node, int key) {
		node->data = key;
		node->parent = NULL; 
		node->right = NULL;
		node->left = NULL;
}
	void preorder(nodepointer node) {
		if (node != NULL) {
			cout << node-> data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(nodepointer node) {
		if (node != NULL){
			postorder(node->left);
		postorder(node->right);
		cout << node->data << " ";
	}
	}
	void inorder(nodepointer node) {
		if (node != NULL) {
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}
	nodepointer searchtree(nodepointer node, int key) {
		if (node == NULL || node->data = key) {
			return node;
		}
		else if (key > node-> data) {
			return searchtree(node->right, key);
		} else {
			return searchtree(node->left, key);
		}
	}

	nodepointer deletenode(nodepointer node, int key) {
		if (node == NULL) { 
			return node;
		}
		else if (key > node->data) {
			node-> right = deletenode(node->right, key);
		}
		else if (key < node->data) {
			node-> left = deletenode(node->left, key);
			}
		else {

			if (node->left == NULL && node->right == NULL) {
				delete node;
				node = NULL;
			}
			if (node->left == NULL) {
				nodepointer temp = node;
				node = node->right;
				delete temp;
			}
			if (node->right == NULL) {
				nodepointer temp = node;
				node = node->left;
				delete temp;
			}
			else {
				nodepointer temp = minimum(node->right);
				node->data = temp->data;
				node->right = deletenode(node->right, temp-> data);
			}
		}
		return node;
	}

public: 
	BST() {
		root = NULL;
	}

	void pre(nodepointer root) {
		preorder(root);
	}
	void in(nodepointer root) {
		inorder(root);
	}
	void post(nodepointer root) {
		postorder(root);
	}
	nodepointer search(int k) {
		return searchtree(root, k);
	}
	nodepointer minimum(node* node) {
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	nodepointer maximum(node* node) {
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}

};