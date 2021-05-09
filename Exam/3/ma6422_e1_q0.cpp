#include <iostream>

using namespace std;

class Operand {
public:
	Operand* left;
	Operand* right;

	Operand() {
		left = nullptr;
		right = nullptr;
	}
};

class OperandNode : public Operand {
public:
	int data;

	OperandNode(int d) : data(d) {}
}; 

class OperatorNode : public Operand {
public:
	char data;

	OperatorNode(char d) : data(d) {}
}; 

class ExpressionTree {
public:
	Operand* root;

	ExpressionTree() : root {nullptr} {}
	ExpressionTree(Operand* node) {
		this->root = node;
	}

	int calculateValue(Operand* node) {
		if(node == nullptr) {
			return 0;
		} 

		// If it is a leaf node.. that is both children are nullptr..then we can return the data.
		if(node->left == nullptr && node->right == nullptr) {
			return static_cast<OperandNode*>(node)->data;
		}

		auto left = calculateValue(node->left);
		auto right = calculateValue(node->right);

		auto op = static_cast<OperatorNode*>(node)->data;

		// I'm just gonna assume good faith that they only choose correct operator.
		if(op == '/') {
			return left / right;
		} else if(op == '+') {
			return left + right;
		} else if(op == '-') {
			return left - right;
		} else {
			return left * right;
		}
	}
};

int main(int argc, char const *argv[]) {
	OperatorNode* root = new OperatorNode('*');
	root->left = new OperatorNode('+');
	root->left->left = new OperandNode(2);
	root->left->right = new OperandNode(3);
	root->right = new OperandNode(7);
	ExpressionTree t(root);
	cout << t.calculateValue(root) << endl;
	delete root->right;
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root;
	return 0;
}
