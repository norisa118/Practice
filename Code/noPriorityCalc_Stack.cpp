#include <iostream>
#include <stack> 
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class myClass {
public:

	stack<char> mystack; 

	void gather() {
		// get user input:
		string calcThis;
		cout << "Type in what you want calculated (single digits only): ";
		cin >> calcThis; 

		// store user input in stack: 
		int len = strlen(calcThis.c_str());
		//cout << "LEN: " << len << endl;
		for (int i = 0; i < len; i++) {
			mystack.push(calcThis[i]);
		}

		/*print stack for debug: 
		while (!mystack.empty()) {
			cout << "TOP IS: " << mystack.top() << endl;
			mystack.pop(); 
		}*/

	}

	int calculate() {
		if (mystack.empty()) cout << "Please Enter Something!!";
		int calcAns = mystack.top() - '0';
		mystack.pop();
		int secNum = 0;

		while (!mystack.empty()) {
			if (mystack.top() == '+') {
				mystack.pop();
				secNum = mystack.top() -'0';
				calcAns = calcAns + secNum;
			}
			else if (mystack.top() == '-') {
				mystack.pop();
				secNum = mystack.top() = '0';
				calcAns = calcAns - secNum;

			}
			else if (mystack.top() == '*') {
				mystack.pop();
				secNum = mystack.top() -'0';
				calcAns = calcAns * secNum;

			}
			else{
				mystack.pop();
				secNum = mystack.top() - '0';
				calcAns = calcAns / secNum;
			}


			//Pop secNum out: 
			mystack.pop();

		}
		return calcAns; 
	}
};


int main() {
	myClass class1;
	class1.gather();
	int ret = class1.calculate(); 
	cout << "Answer: " << ret << endl; 



	return 0;
}