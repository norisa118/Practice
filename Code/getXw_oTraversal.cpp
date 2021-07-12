#include <iostream>
#include <stack>      
using namespace std;

class myClass{
public:
	struct Insert {
		int smallest = INT32_MAX;
		int current = 0; 
	};

	stack<Insert> mystack;

	int retSmallest() {
		if (mystack.empty()) return -1; 
		Insert topInst = mystack.top();
		return topInst.smallest; 
	}

	void pop() {
		mystack.pop();
	}

	void push(int num) {
		Insert i;
		i.current = num;
		Insert topNum;
		if (!mystack.empty()) {
			topNum = mystack.top();
		}
		int topSmallest = topNum.smallest;

		if (num < topSmallest) {
			i.smallest = num;
		}
		else {
			i.smallest = topSmallest;
		}
		mystack.push(i);
	}

};


int main() {
	myClass class1;
	class1.push(5);
	class1.push(2);
	class1.push(8);
	int smallest = class1.retSmallest();
	cout << "Smallest num is: " << smallest << endl;
	class1.pop();
	 smallest = class1.retSmallest();
	cout << "Smallest num is: " << smallest << endl;
	class1.push(10);
	class1.push(0);
	 smallest = class1.retSmallest();
	cout << "Smallest num is: " << smallest << endl;
	class1.pop();
	 smallest = class1.retSmallest();
	cout << "Smallest num is: " << smallest << endl;
	return 0;
}



/*
ARRAY CODE: 

	void storeSmallest(int* arr, int length) {
		//if (arr.empty() == 1) return;

		for (int j = 0; j < length; j++) {

			int num = arr[j];
			//make a struct instance:
			Insert i;
			i.current = num;
			Insert topNum;
			if (!mystack.empty()) {
				topNum = mystack.top();
			}

			int topSmallest = topNum.smallest;
			if (num < topSmallest) {
				i.smallest = num;
			}
			else {
				i.smallest = topSmallest;
			}
			mystack.push(i);
		}
		return;
	}

	int retSmallest() {
		if (mystack.empty()) return -1;
		Insert topInst = mystack.top();
		return topInst.smallest;
	}

	*/