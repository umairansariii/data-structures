#include <iostream>
#include "CircularlyLinkedList.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	List list;
	// Add: populating values from 1 to 5.
	cout << "Added: ";
	for(int i = 1; i <= 5; i++) {
		list.add(i);
		cout << list.get() << " ";	
	};
	cout << endl;
	
	// Length: confirming the total length.
	cout << "Length: " << list.length() << endl;
	
	// Start: updating the pointer to the starting index.
	list.start();
	cout << "Start: " << list.get() << endl;
	
	// Looping: looping list in a circular path.
	cout << "Loop: ";
	for(int i = 1; i <= 13; i++) {
		cout << list.get() << " ";
		list.next();
		
		if ((i % list.length()) == 0) {
			list.next();
		};
	};
	cout << endl;
};
