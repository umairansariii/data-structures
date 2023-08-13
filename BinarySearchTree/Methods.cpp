#include <iostream>
#include <stdlib.h>
#include "BST.cpp"

using namespace std;

void insert(TreeNode<int>* root, int* info) {
	TreeNode<int>* node = new TreeNode<int>(info);
	
	TreeNode<int> *p, *q;
	p = q = root;
	
	while(*info != *(p->getInfo()) && q != NULL) {
		p = q;
		if(*info < *(p->getInfo())) {
			q = p->getLeft();
		} else {
			q = p->getRight();
		};
	};
	if(*info == *(p->getInfo())) {
		cout << "attempt to insert duplicate: " << *info << endl;
		delete node;
	} else if(*info < *(p->getInfo())) {
		p->setLeft(node);
	} else {
		p->setRight(node);
	};
};

void preorder(TreeNode<int>* treeNode) {
	if(treeNode != NULL) {
		cout << *(treeNode->getInfo()) << " ";
		preorder(treeNode->getLeft());
		preorder(treeNode->getRight());
	};
};

void inorder(TreeNode<int>* treeNode) {
	if(treeNode != NULL) {
		inorder(treeNode->getLeft());
		cout << *(treeNode->getInfo()) << " ";
		inorder(treeNode->getRight());
	};
};

void postorder(TreeNode<int>* treeNode) {
	if(treeNode != NULL) {
		postorder(treeNode->getLeft());
		postorder(treeNode->getRight());
		cout << *(treeNode->getInfo()) << " ";
	};
};

int main(int argc, char *argv[]) {
	int x[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 28, 17, 9, 14, 5, -1};
	
	TreeNode<int>* root = new TreeNode<int>();
	root->setInfo(&x[0]);
	
	for(int i = 1; x[i] > 0; i++) {
		insert(root, &x[i]);
	};
	
	cout << "Preorder: "; preorder(root); cout << endl;
	cout << "Inorder: "; inorder(root); cout << endl;
	cout << "Postorder: "; postorder(root); cout << endl;
};
