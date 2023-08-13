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

class List {
	// Private data members of object.
	private:
		int size;
		Node *headNode, *currentNode, *lastCurrentNode;
	public:
		// Default Constructor
		List() {
			this->headNode = new Node();
			this->headNode->setNext(NULL);
			this->currentNode = NULL;
			this->size = 0;
		};
		// Methods
		void add(int addObject) {
			Node *newNode = new Node();
			newNode->set(addObject);
			// this block runs, when at least one node created before.
			if (this->currentNode != NULL) {
				newNode->setNext(this->currentNode->getNext());
				this->currentNode->setNext(newNode);
				this->lastCurrentNode = this->currentNode;
				this->currentNode = newNode;
			}
			// this block runs, while creating first node.
			else {
				newNode->setNext(NULL);
				this->headNode->setNext(newNode);
				this->lastCurrentNode = this->headNode;
				this->currentNode = newNode;
			};
			this->size++;
		};
		void remove() {
			if (this->currentNode != NULL && this->currentNode != this->headNode) {
				this->lastCurrentNode->setNext(this->currentNode->getNext());
				delete this->currentNode;
				this->currentNode = this->lastCurrentNode->getNext();
				size--;
			};
		};
		int get() {
			if (this->currentNode != NULL) {
				return this->currentNode->get();
			};
		};
		bool next() {
			if (this->currentNode == NULL) {
				return false;
			};
			this->lastCurrentNode = this->currentNode;
			this->currentNode = this->currentNode->getNext();
			if (this->currentNode == NULL || this->size == 0) {
				return false;
			} else {
				return true;
			};
		};
		int length() {
			return this->size;
		};
		void start() {
			this->lastCurrentNode = this->headNode;
			this->currentNode = this->headNode;
		};
};
