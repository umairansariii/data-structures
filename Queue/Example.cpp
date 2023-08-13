#include <iostream>
#include "Queue.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	Queue myQueue(5);
	
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Is empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full? " << (myQueue.isFull() ? "Yes" : "No") << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Is empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
};
