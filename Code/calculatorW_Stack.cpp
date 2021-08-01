#include <iostream>
#include <stack> 
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class myClass {
public:
	struct Pri {
		char op;
		int pri; 
	};
	stack<Pri> operators;
	stack<char> numbers;


	void gather() {
		// get user input:
		string calcThis;
		cout << "Type in what you want calculated (single digits only): ";
		cin >> calcThis;
		
		// store user input in stack: 
		int len = strlen(calcThis.c_str());
		for (int i = 0; i < len; i++) {
			 
			Pri priObj;
			priObj.op = 'x';
			priObj.pri = -1;

			if (calcThis[i] == '(' || calcThis[i] == ')') {
				priObj.op = calcThis[i];
				priObj.pri = 1;
			}
			else if (calcThis[i] == '*' || calcThis[i] == '/') {
				priObj.op = calcThis[i];
				priObj.pri = 2;
			}
			else if (calcThis[i] == '-' || calcThis[i] == '+') {
				priObj.op = calcThis[i];
				priObj.pri = 3;
			}
			else {
				numbers.push(calcThis[i]);
			}

			char send = ' '; 
			if (!(priObj.op == 'x')) {
				if(operators.empty()) operators.push(priObj);
				else {
					// We compare the precedence of the operators, the × is prior than +. 
					//So we pop × out of the stack. And × needs two parameters, so we push
					//two operands out of the operands stack. And then do the calculation 3×2. 
					//We get 6. Push 6 to the operands stack.

					//compare precedence of the operators: 
					if (priObj.pri < operators.top().pri) {
						//current operator is less priority than current top
						send = operators.top().op;
						operators.pop(); 
						char insert = calculate(send);
						numbers.push(insert);
					}
				}
			}
			


		
		}

		while (!numbers.empty()) {
			cout << "NUMBER: " << numbers.top() << endl;
			numbers.pop();
		}

		while (!operators.empty()) {
			cout << "OPERATOR: " << operators.top().op << " PRI: " << operators.top().pri << endl;
			operators.pop();
		}


	}

	

	int calculate(char char_in) {
	
		int calcAns = numbers.top() - '0';
		numbers.pop();
		int secNum = 0;

		if (char_in == '+') {
			secNum = numbers.top() - '0';
			calcAns = calcAns + secNum;
		}
		else if (char_in == '-') {
			secNum = numbers.top() = '0';
			calcAns = calcAns - secNum;

		}
		else if (char_in == '*') {
			secNum = numbers.top() - '0';
			calcAns = calcAns * secNum;

		}
		else if (char_in == '/') {
			secNum = numbers.top() - '0';
			calcAns = calcAns / secNum;

		}
		else {
			// () NOT TAKEN CARE OF HERE !!!!!11
			cout << "PARENTHESES" << endl; 
		}

		

		//Pop secNum out: 
		numbers.pop();
		return calcAns;
	}
};


int main() {
	myClass class1;
	class1.gather();
	cout << "Answer: " << 0 << endl;

	return 0;
}