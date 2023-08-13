#include <iostream>

using namespace std;

class Node {
	// Private data members of object.
	private:
		int object;
		Node *nextNode;
	public:
		int get() {
			return this->object;
		};
		void set(int object) {
			this->object = object;
		};
		Node *getNext() {
			return this->nextNode;
		};
		void setNext(Node *nextNode) {
			this->nextNode = nextNode;
		};
};

class Stack {
	// Private data members of object.
	private:
		Node *head;
	public:
		// Default constructor
		Stack() {
        	this->head = NULL;
    	};
    	~Stack() {
        	while(!this->isEmpty()) {
            	this->pop();
        	};
    	};
		int pop() {
			if(this->isEmpty()) {
            	cout << "Stack is empty." << endl;
        	};
			int x = this->head->get();
			Node *p = this->head;
			head = head->getNext();
			delete p;
			return x;
		};
		void push(int x) {
			Node *newNode = new Node();
			newNode->set(x);
			newNode->setNext(this->head);
			this->head = newNode;
		};
		int top() {
			if(this->isEmpty()) {
            	cout << "Stack is empty." << endl;
        	};
			return this->head->get();
		};
		bool isEmpty() {
			return (this->head == NULL);
		};
};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "Top element: " << myStack.top() << endl;

    while(!myStack.isEmpty()) {
        cout << "Popped: " << myStack.pop() << endl;
    };
    cout << "Is empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
};
