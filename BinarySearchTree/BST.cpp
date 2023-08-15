#include <stdlib.h>

template <class T>
class TreeNode {
	private:
		T* info;
		TreeNode<T>* left;
		TreeNode<T>* right;
	public:
		// Default constructor
		TreeNode() {
			this->info = NULL;
			this->left = this->right = NULL;
		};
		// Parameterized constructor
		TreeNode(T* x) {
			this->info = x;
			this->left = this->right = NULL;
		};
		T* getInfo() const {
			return this->info;
		};
		void setInfo(T* x) {
			this->info = x;
		};
		TreeNode<T>* getLeft() const {
			return this->left;
		};
		void setLeft(TreeNode<T>* x) {
			this->left = x;
		};
		TreeNode<T>* getRight() const {
			return this->right;
		};
		void setRight(TreeNode<T>* x) {
			this->right = x;
		};
		int isLeaf() {
			if(this->left == NULL && this->right == NULL) {
				return 1;
			} else {
				return 0;
			};
		};
};
