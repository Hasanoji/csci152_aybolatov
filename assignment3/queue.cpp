#include "queue.h"

// class queue {

// 	// Private type for internal queue use only
// 	struct node {
// 		int value;
// 		node* next;
// 		// node constructor
// 		node(int x): value(x), next(nullptr) { }
// 	};

// 	// Fields of the queue object
	
// 	size_t queue_size;

// 	node* front;
// 	node* back;

// public:

	// Creates an empty queue
	// queue(): 
	//      queue_size(0), 
	// 	 front(nullptr), 
	// 	 back(nullptr) 
	// { }

	// Copy constructor
		queue::queue(const queue& q) {
		node *new_node = q.front;
		front = nullptr;
		back = nullptr;
		queue_size = 0;
		while(new_node != nullptr) {
			push(new_node->value);
			new_node = new_node->next;
		}
	}

	// Initializer list constructor
	queue::queue(std::initializer_list<int> ilist) {
		front = nullptr;
		back = nullptr;
		queue_size = 0;
		for(auto i : ilist) {
			push(i);
		}
	}

	// Copy assignment
	queue& queue::operator=(const queue& q) {
		if (front != q.front){
			clear();
			front = nullptr;
			back = nullptr;
			queue_size = 0;
			node *new_node = q.front;
			while(new_node != nullptr) {
				push(new_node->value);
				new_node = new_node->next;
			}
		}
		return *this;
	}

	// Insert an item at the back of the queue
	void queue::push(int val){
		node *new_node = new node (val);
		if(!size()) {
			front = new_node;
			back = new_node;
		}
		else {
			back -> next = new_node;
			back = new_node;
		}
		queue_size++;
	}
	// Returns the value of the front-most item of the queue;
	// throws an exception if the queue is empty
	int queue::peek() const {
		if(!size()) throw std::invalid_argument("queue is empty, nothing to peek");
		return (front -> value);
	}

	// Remove the front-most item from the queue
	// throws an exception if the queue is empty
	void queue::pop() {
		if(!queue_size) throw std::runtime_error ("queue is empty, nothing to pop");
		node *next_node = front->next;
		delete front;
		front = next_node;
		queue_size--;
	}

	// Remove everything from the queue
	void queue::clear() {
		while(!empty()) pop();
	}
	// Returns the number of items on the queue
	size_t queue::size() const {
		return queue_size;
	}

	// Returns whether or not the queue is currently empty
	bool queue::empty() const {
		return (queue_size == 0);
	}


	// Destructor
	queue::~queue() {
		while(!empty()) pop();
	}