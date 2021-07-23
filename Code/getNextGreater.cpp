#include <iostream>
#include <stack> 

using namespace std;

class myClass {
public:

	struct Insert {
		int index = -1;
		int current = 0;
	};
	stack<Insert> mystack;


	int* retNextGreater(int* arr, int size) {
		int* ret;
		cout << "here 1" << endl;
		for (int i = 0; i < size; ++i) {
			if (mystack.empty()) {
				Insert inst;
				inst.current = arr[i];
				inst.index = i;
				cout << " I : " << i << endl;
				mystack.push(inst);
				cout << "here 2 :" << inst.current << " " << inst.index << endl;

				// probably a better way to do this: 
				if (i == size - 1) {
					ret[i] = inst.current;
				}
			}

			else {

				//check if one next to it is smaller, if smaller or equal push in, if greater, set as g:
				cout << "here 3" << endl;

				if (arr[i] <= mystack.top().current) {
					Insert inst;
					inst.current = arr[i];
					inst.index = i;
					mystack.push(inst);
					cout << "here 4" << endl;
				}

				else {
					// get index of the top of the stack and
					while (!mystack.empty()) {
						if (mystack.top().current < arr[i]) {
							cout << "I RWPA: " << i << endl;
							ret[i] = arr[i]; 
							ret[mystack.top().index] = arr[i];
							cout << "ARR I: " << arr[i] << endl; 
							cout << "INDEX: " << ret[mystack.top().index] << endl;
							mystack.pop();
						}
						if (mystack.empty()) cout << "ITS EMPTY" << endl;
						else {
							cout << "breaking" << endl;
							break;
						}
					} // end of while 

				} // end of inner else 
				cout << "here 5" << endl;
			

			} // end of outer else 
			cout << "here 6: " << i << endl;

		} // end of for
		return ret;
	}
	};



	int main() {
		//assuming every number is positive:
		myClass class1;
		int realArr[5] = { 2, 5, 1, 2, 1 };
		int size = sizeof(realArr) / sizeof(realArr[0]);
		int* returned = class1.retNextGreater(realArr, size);
		//print returned in a for loop: 
		for (int i = 0; i < sizeof(realArr) / sizeof(realArr[0]); ++i) {
			cout << returned[i] << endl;
		}
		delete[] returned;
		return 0;
	}

	//output should be 5,5,2,2,1 ?? 
	