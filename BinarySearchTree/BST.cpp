#include <stdlib.h>
template <class Object>

class TreeNode {
	private:
		Object* object;
		TreeNode* left;
		TreeNode* right;
	
	public:
		// Default constructor
		TreeNode() {
			this->object = NULL;
			this->left = this->right = NULL;
		};
		// Parameterized constructor
		TreeNode(Object* object) {
			this->object = object;
			this->left = this->right = NULL;
		};
		Object* getInfo() {
			return this->object;
		};
		void setInfo(Object* object) {
			this->object = object;
		};
		TreeNode* getLeft() {
			return left;
		};
		void setLeft(TreeNode *left) {
			this->left = left;
		};
		TreeNode* getRight() {
			return right;
		};
		void setRight(TreeNode *right) {
			this->right = right;
		};
		int isLeaf() {
			if(this->left == NULL && this->right == NULL) {
				return 1;
			} else {
				return 0;
			};
		};
};
