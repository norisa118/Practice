#include <iostream>
#include <stack> 

using namespace std;

class myClass {
public:
	struct Insert {
		int count = -1;
		int current = -1;
	};

	stack<Insert> mystack;

	void printStack() {
		while (!mystack.empty()) {
			cout << mystack.top().current << " , " << mystack.top().count << endl;
			mystack.pop();
		}
	}

	void pushIn(int num) {
		Insert i;
		if (mystack.empty()) {
			i.current = num;
			i.count = 1;
			mystack.push(i);
		}

		// IF IS OVER 


		else {
			if (mystack.top().current == num) {
				i.current = num;
				i.count = mystack.top().count + 1;
				mystack.push(i);
			}
			else {
				i.current = num;
				i.count = 1;
				mystack.push(i);
			}

		}

		// ELSE IS OVER



	}
};


int main() {
	myClass class1;
	class1.pushIn(1);
	class1.pushIn(1);
	class1.pushIn(1);
	class1.pushIn(1);
	class1.pushIn(1);

	class1.printStack();
	return 0;
}