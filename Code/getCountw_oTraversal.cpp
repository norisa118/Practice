#include <iostream>
#include <stack>      
using namespace std;

class myClass {
public:
	struct Insert {
		int count = 0;
		int current = 0;
	};

	stack<Insert> mystack;
	stack<Insert> tempstack;


	int retCount() {
		stackTop = mystack.top();
		return stackTop.count; 
	}


	void push(int num) {
		Insert i;
		if (mystack.empty()) {
			i.count = 1;
			i.current = num;
			mystack.push(i);
		}
		//check if top is num
		if (mystack.top() == num) {
			//if top is num, increment count
			mystack.top().count = mystack.top().count + 1; 
		}
		//else if not, pop into another stack until top is num, and then put back into the stack
		while (!mystack.empty()) {
			tempstack.push(mystack.top());
			mystack.pop();
			if (mystack.top() == num) {
				//if top is num, increment count
				mystack.top().count = mystack.top().count + 1;
				break; 
			}
		} // end of loop 

		//not in the stack, so put it in the stack and increment: 
		i.count = 1;
		i.current = num; 
		mystack.push(i);
		

};


int main() {
	myClass class1;
	class1.push(5);
	class1.push(2);
	class1.push(8);
	class1.push(2);
	class1.push(2); 
	int count = class1.retCount();
	cout << "You have pushed this number in" << count << " times. " << endl;
	
	return 0;
}
