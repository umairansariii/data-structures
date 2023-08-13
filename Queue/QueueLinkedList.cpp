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

class Queue {
	// Private data members of object.
	private:
		Node *front;
		Node *rear;
	public:
		// Default constructor
		Queue() {
        	this->front = NULL;
        	this->rear = NULL;
   		};
    	~Queue() {
        	while(!this->isEmpty()) {
            	this->dequeue();
        	};
    	};
		int dequeue() {
			if(this->isEmpty()) {
            	cout << "Queue is empty." << endl;
        	};
			int x = this->front->get();
			Node *p = this->front;
			this->front = this->front->getNext();
			delete p;
			if(this->front == NULL) {
            	this->rear = NULL;
        	};
			return x;
		};
		void enqueue(int x) {
			Node *newNode = new Node();
			newNode->set(x);
			newNode->setNext(NULL);
			if(this->isEmpty()) {
            	this->front = newNode;
            	this->rear = newNode;
            } else {
            	this->rear->setNext(newNode);
				this->rear = newNode;
			};
		};
		int getFront() {
			if(this->isEmpty()) {
            	cout << "Queue is empty." << endl;
        	};
			return this->front->get();
		};
		bool isEmpty() {
			return (this->front == NULL);
		};
};

int main(int argc, char *argv[]) {
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.getFront() << endl;

    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.dequeue() << endl;
    };
    cout << "Is empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
