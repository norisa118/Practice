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
		int* ret = new int [size];
		for (int i = 0; i < size; ++i) {
			if (mystack.empty()) {
				Insert inst;
				inst.current = arr[i];
				inst.index = i;
				mystack.push(inst);

				// probably a better way to do this: 
				if (i == (size - 1)) {
					ret[i] = -1;
				}
			}

			else {

				//check if one next to it is smaller, if smaller or equal push in, if greater, set as g:

				if (arr[i] <= mystack.top().current) {
					Insert inst;
					inst.current = arr[i];
					inst.index = i;
					mystack.push(inst);
				}

				else {
					// get index of the top of the stack and
					int pushInt = 0; 
					int pushIndex = 0; 
					while (!mystack.empty()) {
						if (mystack.top().current < arr[i]) {
							//ret[i] = arr[i]; // 1,2,3,4 5
							// 2,x,x,x,x
							ret[mystack.top().index] = arr[i];
							pushInt = arr[i];
							pushIndex = i; 
							mystack.pop();
						}
						else {
							break;
						}
					} // end of while 

					//stack is now empty so push in greatest and its index
					Insert pushIn;
					pushIn.current = pushInt; 
					pushIn.index = pushIndex; 
					mystack.push(pushIn);

				} // end of inner else 
			

			} // end of outer else 

		} // end of for
		return ret;
	}
	};



	int main() {
		//assuming every number is positive:
		myClass class1;
		int realArr[5] = { 3,25,2,1,6};
		int size = sizeof(realArr) / sizeof(realArr[0]);
		int* returned = class1.retNextGreater(realArr, size);
		//print returned in a for loop: 
		for (int i = 0; i < sizeof(realArr) / sizeof(realArr[0]); ++i) {
			cout << returned[i] << endl;
		}
		delete[] returned; 
		return 0;
	}
	
	// out: 25,0,6,6,0

