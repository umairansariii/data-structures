#include "Stack.cpp"

int main(int argc, char *argv[]) {
	Stack<int> intstack;
	Stack<char> charstack;
	
	int x = 10, y = 20;
	char c = 'C', d = 'D';
	
	intstack.push(x);
	intstack.push(y);
	cout << "IntStack: " << intstack.pop() << ", " << intstack.pop() << endl;
	
	charstack.push(c);
	charstack.push(d);
	cout << "CharStack: " << charstack.pop() << ", " << charstack.pop() << endl;
};
