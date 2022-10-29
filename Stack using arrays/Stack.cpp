#include <iostream>
using namespace std;

//#define STACK_MAX_SIZE (10)
//template<typename T>
//typedef struct Stack Stack;

struct Stack
{
	int top = -1;
	int MAX_SIZE = 0;
	int* stack = NULL;

	bool createStack(int SIZE){
		MAX_SIZE = SIZE;
		stack = (int*)malloc( MAX_SIZE * sizeof(int) );
		return (stack != NULL);  //memory allocated successfully
	}

	void clear(void){
		free(stack);
		stack = NULL;
		top = -1;
		MAX_SIZE = 0;
	}

	bool isEmpty(void) {
		return (top <= -1);
	}

	bool isFull(void) {
		return (top >= MAX_SIZE - 1);
	}

	int SIZE(void){
		return (top + 1);
	}
	
	bool push(int val) {
		if (isFull()) {
			cout << "Stack Overflow" << '\n';
			return false;
		}
		++top;
		stack[top] = val;
		return true;           // pushed into stack successfully
	}

	int pop(void) {
		if (isEmpty()) {
			cout << "Stack Underflow" << '\n';
		}
		else {
			int temp = stack[top];
			--top;
			return temp;
		}
	}

	int peek(void) {
		if (!isEmpty()) {
			return stack[top];
		}
	}

	void print(void)
	{
		for (int i = top; i > -1; --i){
			cout << stack[i] << "\n";
		}
	}
};

int main() {

	Stack s;

	s.createStack(10);

	s.push(1);
	s.push(2);
	s.push(3);

	cout << "top is:  " << s.peek() << '\n';
	s.pop();

	cout << "stack MAX_SIZE: " << s.MAX_SIZE << '\n';
	cout << "stack SIZE: " << s.SIZE() << '\n';


	s.print();

	s.clear();



	return 0;
}
