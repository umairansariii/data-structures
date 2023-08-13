class Queue {
	// Private data members of object.
	private:
		int size;
    	int front;
    	int rear;
    	int noElements;
    	int* array;
	public:
		// Parameterized constructor
		Queue(int maxSize) {
        	this->size = maxSize;
        	this->array = new int[size];
        	this->front = 0;
        	this->rear = size - 1;
        	this->noElements = 0;
    	}
		~Queue() {
        	delete[] this->array;
    	};
		void enqueue(int x) {
			this->rear = (this->rear+1) % this->size;
			this->array[this->rear] = x;
			this->noElements = this->noElements+1;
		};
		int dequeue() {
			int x = this->array[this->front];
			this->front = (this->front+1) % this->size;
			this->noElements = this->noElements-1;
			return x;
		};
		int isFull() {
			return this->noElements == this->size;
		};
		int isEmpty() {
			return this->noElements == 0;
		};
};
