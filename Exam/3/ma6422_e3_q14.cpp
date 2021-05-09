#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

// Trees are identical if and only if every pointer and every data value is identical. We can do this recursively!
bool isSameTree(TreeNode* p, TreeNode* q) {
	if(p == nullptr && q == nullptr) {
		return true; // This is obviously true if both nodes from each tree are null.
	} else if(p != nullptr && q != nullptr) {
		bool data = (p->val == q->val);
		bool left_identical = isSameTree(p->left, q->left); // We want to check the same sub-tree against each other.
		bool right_identical = isSameTree(p->right, q->right); // We want to check the same sub-tree against each other.
		return (data && right_identical && left_identical);
	} else {
		return false; // If one is null and other isn't, they're obviously not the same.
	}
}

// For a tree to be symmetric it means that every left branch is equal to the right branch. So for example.
// root->right = root->left, and this must hold true for every recursion. 
// Hence the tree must be mirrored about it's root node, which will need a helper function that takes two different sub-trees to compare them.
bool mirrored(TreeNode* p, TreeNode* q) {
	if(p == nullptr && q == nullptr) {
		return true; // This is obviously true, same as before.
	} else if(p && q && p->val == q->val) { // For this section we must have the root nodes not be nullptr, and the keys must be the same. Then we go recursively!
		bool left_mirrored = mirrored(p->left, q->right);
		bool right_mirrored = mirrored(p->right, q->left);
		return (left_mirrored && right_mirrored);
	} else {
		return false;
	}
}

bool isSymmetric(TreeNode* root) {
	return mirrored(root, root);
}

// Level order traversal is essentially just utilizing a queue to do so. We push the 
void levelOrder(TreeNode* root) {
	if(root == nullptr) {
		return; // Empty tree.
	}

	// Queue will hold our nodes to print out in the correct order.
	queue<TreeNode*> q;
	q.push(root); 

	// Go through the queue and get te front most item, pop it off, print it and then queue it's children, left and right.
	while(!q.empty()) {
		TreeNode* n = q.front();
		cout << n->val << " ";
		q.pop();

		if(n->left != nullptr) {
			q.push(n->left);
		}

		if(n->right != nullptr) {
			q.push(n->right);
		}
	}
	cout << endl;
}

// Some basic driving code to experiment with.
// I realize I don't delete these but honestly I can't be bothered at the moment.
int main(int argc, char const *argv[]) {
	// Test level-order printing first.
	{
 		TreeNode *root = new TreeNode(1); 
		root->left = new TreeNode(2); 
		root->right = new TreeNode(3); 
		root->left->left = new TreeNode(4); 
		root->left->right = new TreeNode(5); 
		levelOrder(root);
	}

	// Test symmetry of the trees.
	{
		TreeNode *root = new TreeNode(1); 
		root->left = new TreeNode(2); 
		root->right = new TreeNode(2); 
		root->left->left = new TreeNode(4); 
		root->left->right = new TreeNode(3); 
		root->right->left = new TreeNode(3); 
		root->right->right = new TreeNode(4);
		cout << (isSymmetric(root) ? "Symmetric!" : "Not Symmetric!") << endl;
		root->right->right->right = new TreeNode(4);
		cout << (isSymmetric(root) ? "Symmetric!" : "Not Symmetric!") << endl;
	}

	// Testing if trees are identical.
	{
		TreeNode *root1 = new TreeNode(1); 
		root1->left = new TreeNode(2); 
		root1->right = new TreeNode(2); 
		root1->left->left = new TreeNode(4); 
		root1->left->right = new TreeNode(3); 
		root1->right->left = new TreeNode(3); 
		root1->right->right = new TreeNode(4);

		TreeNode *root2 = new TreeNode(1); 
		root2->left = new TreeNode(2); 
		root2->right = new TreeNode(2); 
		root2->left->left = new TreeNode(4); 
		root2->left->right = new TreeNode(3); 
		root2->right->left = new TreeNode(3); 
		root2->right->right = new TreeNode(4);

		cout << (isSameTree(root1, root2) ? "Identical!" : "Not Identical!") << endl;

		root2->right->right->right = new TreeNode(4);

		cout << (isSameTree(root1, root2) ? "Identical!" : "Not Identical!") << endl;
	}
	return 0;
}
