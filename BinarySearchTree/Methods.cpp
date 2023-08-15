#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "QueueT.cpp"
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
		cout << "Attempt to insert duplicate: " << *info << endl;
		delete node;
	} else if(*info < *(p->getInfo())) {
		p->setLeft(node);
	} else {
		p->setRight(node);
	};
};
void insert(TreeNode<char>* root, char* info) {
	TreeNode<char>* node = new TreeNode<char>(info);
	
	TreeNode<char> *p, *q;
	p = q = root;
	
	while(strcmp(info, p->getInfo()) != 0 && q != NULL) {
		p = q;
		if(strcmp(info, p->getInfo()) < 0) {
			q = p->getLeft();
		} else {
			q = p->getRight();
		};
	};
	if(strcmp(info, p->getInfo()) == 0) {
		cout << "Attempt to insert duplicate: " << info << endl;
		delete node;
	} else if(strcmp(info, p->getInfo()) < 0) {
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
void inorder(TreeNode<char>* treeNode) {
	if(treeNode != NULL) {
		inorder(treeNode->getLeft());
		cout << treeNode->getInfo() << " ";
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
void levelorder(TreeNode<int>* treeNode) {
	Queue<TreeNode<int>*> q(100);
	if(treeNode == NULL) return;
	q.enqueue(treeNode);
	while(!q.isEmpty()) {
		treeNode = q.dequeue();
		cout << *(treeNode->getInfo()) << " ";
		if(treeNode->getLeft() != NULL) {
			q.enqueue(treeNode->getLeft());
		};
		if(treeNode->getRight() != NULL) {
			q.enqueue(treeNode->getRight());
		};
	};
	cout << endl;
};

int main(int argc, char *argv[]) {
	// For integers ---------------------------------------:
	cout << "Integers:" << endl;
	int x[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 28, 17, 9, 14, 5, -1};
	
	TreeNode<int>* root = new TreeNode<int>();
	root->setInfo(&x[0]);
	
	for(int i = 1; x[i] > 0; i++) {
		insert(root, &x[i]);
	};
	cout << "Preorder: "; preorder(root); cout << endl;
	cout << "Inorder: "; inorder(root); cout << endl;
	cout << "Postorder: "; postorder(root); cout << endl;
	cout << "Levelorder: "; levelorder(root); cout << endl;
	
	// For characters -------------------------------------:
	cout << "Characters:" << endl;
	char* fruits[] = {"mango", "kiwi", "watermelon", "mango", "apple", "banana", "orange", "pineapple", NULL};
	
	TreeNode<char>* words = new TreeNode<char>();
	words->setInfo(fruits[0]);
	
	for(int i = 1; fruits[i]; i++) {
		insert(words, fruits[i]);
	};
	cout << "Inorder: "; inorder(words); cout << endl;
};
