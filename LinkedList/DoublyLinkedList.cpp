class Node {
	// Private data members of object.
	private:
		int object;
		Node *nextNode;
		Node *prevNode; // +added previous pointer.
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
		// +added getter and setter for previous pointer.
		Node *getPrev() {
			return this->prevNode;
		};
		void setPrev(Node *prevNode) {
			this->prevNode = prevNode;
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
			this->headNode->setPrev(NULL); // +set previous pointer to NULL.
			this->currentNode = NULL;
			this->size = 0;
		};
		// Methods
		void add(int addObject) {
			Node *newNode = new Node();
			newNode->set(addObject);
			newNode->setPrev(this->currentNode); // +set previous pointer of new node.
			// this block runs, when at least one node created before.
			if (this->currentNode != NULL) {
				newNode->setNext(this->currentNode->getNext());
				this->currentNode->setNext(newNode);
				// +update previous pointer of the next node.
				if (newNode->getNext() != NULL) {
                	newNode->getNext()->setPrev(newNode);
            	};
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
				// +update previous pointer of the next node.
				if (this->currentNode->getNext() != NULL) {
                	this->currentNode->getNext()->setPrev(this->lastCurrentNode);
            	};
				delete this->currentNode;
				this->currentNode = this->lastCurrentNode->getNext();
				// +update previous pointer of the new current node.
				if (this->currentNode != NULL) {
                	this->currentNode->setPrev(this->lastCurrentNode);
            	};
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
