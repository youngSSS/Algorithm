#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int value) : val(value) {}
} Node;

class BST {
 private:
	Node* root;

	Node* insertValue(Node* node, int value, int& retVal) {
		if (node == nullptr) return new Node(value);

		if (value > node->val)
			node->right = insertValue(node->right, value, retVal);
		else if (value < node->val)
			node->left = insertValue(node->left, value, retVal);

		retVal = 1;
		return node;
	}

	Node* deleteValue(Node* node, int value, int& retVal) {
		if (node == nullptr) {
			retVal = 1;
			return nullptr;
		}

		if (value > node->val) node->right = deleteValue(node->right, value, retVal);
		else if (value < node->val) node->left = deleteValue(node->left, value, retVal);
		else {
			Node* child;

			if (!node->right && !node->left) {
				delete(node);
				return nullptr;
			}
			else if (node->right && node->left) {
				child = findSuccessor(node);
				node->val = child->val;
				node->right = deleteValue(node->right, value, retVal);
			}
			else {
				if (node->left == nullptr) child = node->right;
				else child = node->left;

				delete(node);
				return child;
			}
		}

		return node;
	}

	Node* findValue(Node* node, int value) {
		if (node == nullptr) return nullptr;

		if (value > node->val) return findValue(node->right, value);
		else if (value < node->val) return findValue(node->left, value);
		else return node;
	}

	static Node* findSuccessor(Node* node) {
		node = node->right;

		while (node->left)
			node = node->left;

		return node;
	}

	void inorder(Node* node) {
		if (node == nullptr) return;

		inorder(node->left);
		cout << node->val << " ";
		inorder(node->right);
	}

 public:
	void cmdInsert(int value) {
		int retVal = 0;

		root = insertValue(root, value, retVal);

		if (retVal == 0) cout << "Success - Insertion, " << value << endl;
		else cout << "Failed - Insertion\nDuplicate value, " << value << endl;
	}

	void cmdDelete(int value) {
		int retVal = 0;

		deleteValue(root, value, retVal);

		if (retVal == 0) cout << "Success - Deletion, " << value << endl;
		else cout << "Failed - Deletion\nThe value does not exist, " << value << endl;
	}

	void cmdFind(int value) {
		Node* node = findValue(root, value);

		if (node != nullptr) cout << "Success - Find, " << value << endl;
		else cout << "Failed - Find\nThe value does not exist, " << value << endl;
	}

	void cmdPrint() {
		inorder(root);
	}

};

int main() {
	BST* bst = new BST();

	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 100; i++)
		bst->cmdInsert(rand() % 100);
	bst->cmdDelete(3);
	bst->cmdFind(3);
	bst->cmdFind(7);
	bst->cmdPrint();

	return 0;
}
