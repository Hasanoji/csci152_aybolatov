#include "stack.h"

// // Creates an empty stack
// 	stack() :
// 		values(new int[5]),
// 		stack_size(0),
// 		array_capacity(5)
// 	{
// 	}
	// Copy constructor
	stack::stack(const stack& stk) {
		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;
		values = new int[array_capacity];
		for(int i = 0; i < stack_size; ++i) {
			values[i] = stk.values[i];
		}
	}

	// Initializer list constructor
	stack::stack(std::initializer_list<int> ilist) {
		values = new int[ilist.size() * 2];
		array_capacity = ilist.size() * 2;
		stack_size = ilist.size();
		int i = 0;
		for(auto item : ilist) {
			values[i] = item;
			i++;
		}
	}

	// Copy assignment
	stack& stack::operator=(const stack& stk) {
		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;
		delete values;
		values = new int[array_capacity];
		for(int i = 0; i < stack_size; ++i) {
			values[i] = stk.values[i];
		}
	}

	// Insert an item at the top of the stack
	void stack::push(int val) {
		if(array_capacity == stack_size) {
			int *new_values = new int[array_capacity * 2];
			for(int i = 0; i < stack_size; ++i) {
				new_values[i] = values[i];
			}
			delete values;
			values = new_values;
			values[stack_size] = val;
			stack_size++;
			array_capacity *= 2;
		}
		else {
			values[stack_size] = val;
			stack_size++;
		}
	}

	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int stack::peek() const {
		return values[stack_size - 1];
	}

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop() {
		if(!stack_size) throw std::runtime_error("Stack is empty, nothing to remove");
		else {
			values[stack_size - 1] = 0;
			stack_size--;
		}
	}

	// Remove everything from the stack
	void stack::clear() {
		for(int i = 0; i < stack_size; ++i) {
			values[i] = 0;
		}
		stack_size = 0;
	}

	// Returns the number of items on the stack
	size_t stack::size() const {
		return stack_size;
	}

	// Returns whether or not the stack is currently empty
	bool stack::empty() const {
		return (stack_size == 0);
	}


	// Destructor
	stack::~stack() {
		delete values;
	}
