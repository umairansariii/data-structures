#include <iostream>
#include <stdlib.h>
#define MAXSTACKSIZE 50

using namespace std;

template <class T>
class Stack {
	private:
		int top;
		T *nodes;
	public:
		Stack();
		int empty(void);
		int push(T &);
		T pop(void);
		T peek(void);
		~Stack();
};
template <class T>
Stack<T>::Stack() {
	this->top = -1;
	this->nodes = new T[MAXSTACKSIZE];
};
template <class T>
Stack<T>::~Stack() {
	delete this->nodes;
};
template <class T>
int Stack<T>::empty(void) {
	if(this->top < 0) {
		return 1;
	};
	return 0;
};
template <class T>
int Stack<T>::push(T &x) {
	if(this->top < MAXSTACKSIZE) {
		this->nodes[++top] = x;
		return 1;
	};
	cout << "Stack overflow in push." << endl;
	return 0;
};
template <class T>
T Stack<T>::pop(void) {
	T x;
	if(!this->empty()) {
		x = this->nodes[this->top--];
		return x;
	};
	cout << "Stack underflow in pop." << endl;
	return x;
};
