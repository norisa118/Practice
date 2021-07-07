#include <iostream>
#include <stack>      
using namespace std; 

stack<char> mystack;

bool fnc(string str) {
	//push in until ')' is encountered: 
	bool found = false; 
	if (str == "") return false; 
	for (char c : str) {
		found = false;
		if (c != ')') mystack.push(c); 
		//')' is enountered: 
		else {
			while (!mystack.empty()) {
				if (mystack.top() != '(') mystack.pop();
				if (mystack.top() == '(') {
					found = true;
					mystack.pop();
					break;
				}
			}
			if (!found) return false;
		}
	}


	while (!mystack.empty()) {
		if(!mystack.empty()){
			if (mystack.top() == '(' || mystack.top() == ')') {
				return false;
			}
			else {
				mystack.pop(); 
			}
		}
	}
	return true; 
}

int main() {
	cout << fnc("aaa") << endl; 
	return 0; 
}