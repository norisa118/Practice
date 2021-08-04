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


	int gather() {
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
					if (priObj.pri > operators.top().pri) {    // GREATER number is LESSER priority ** 
						//current operator is less priority than current top
						send = operators.top().op;
						// CHANGED: operators.pop(); 
						//cout << "SEND: " << send << endl; 
						char insert = '0' + calculate(send);
						numbers.push(insert);
					}
					else {
						//Then comes to (. We find that the ( is prior to +, so we push ( to the stack.
						operators.push(priObj);
					}
				}
			}

			if(!numbers.empty()) cout << "NUMBER ON TOP: " << numbers.top() << endl; 
			if (!operators.empty()) cout << "OP ON TOP: " << operators.top().op << endl;
		}

		// MISSING STEP: 
		// We pop the operators out and do the calculation until there is nothing in the operation stack: 
		int ret = 0; 
		while (!operators.empty()) {
			char send2 = operators.top().op;
			cout << "SENDING THIS: " << send2 << endl; 
			char insert = '0' + calculate(send2);
			// CHANGED: operators.pop();
			cout << "THIS IS BEING PUSHED: " << insert << endl; 
			numbers.push(insert);
		}

		return (numbers.top() - '0'); 

	}

	

	int calculate(char char_in) {
		//cout << "COMING TO CALCULATE REE " << endl;
		int calcAns = numbers.top() - '0';
		cout << "NUM 1: " << calcAns << endl; 
		//cout << " CALC ANS IS: " << calcAns << endl; 
		numbers.pop();
		int secNum = 0;

		if (char_in == '+') {
			secNum = numbers.top() - '0';
			cout << "NUM 2: " << secNum << endl;
			calcAns = calcAns + secNum;
			cout << "FINAL ANS: " << calcAns << endl;

		}
		else if (char_in == '-') {
			secNum = numbers.top() - '0';
			cout << "NUM 2: " << secNum << endl;
			calcAns = secNum - calcAns;
			cout << "FINAL ANS: " << calcAns << endl;

		}
		else if (char_in == '*') {
			//cout << "Coming to right spot" << endl; 
			secNum = numbers.top() - '0';
			cout << "NUM 2: " << secNum << endl;
			//cout << "SECNUM: " << secNum << endl;
			calcAns = calcAns * secNum;
			cout << "FINAL ANS: " << calcAns << endl;

		}
		else if (char_in == '/') {
			secNum = numbers.top() - '0';
			cout << "NUM 2: " << secNum << endl;
			calcAns = secNum / calcAns;
			cout << "FINAL ANS: " << calcAns << endl;

		}
		else {
			// () NOT TAKEN CARE OF HERE !!!!!11
			cout << "PARENTHESES" << endl; 
		}

		//Pop secNum out: 
		numbers.pop();
		operators.pop(); 
		return calcAns;
	}
};


int main() {
	myClass class1;
	int ans = class1.gather();
	cout << "Answer: " << ans << endl;

	return 0;
}