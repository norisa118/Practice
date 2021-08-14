#include <iostream>
#include <string>
#include <array>
using namespace std;


class myClass {
private:
	static const int MAX = 5; //why does this have to be static?
	int arr[MAX] = {255, 255, 255, 255, 255}; //initially empty array
	//index start of arr:
	int front = -1;
	//index of back of arr:
	int back = -1;

public:
	void insert(int val, char direction) {
		if (front == -1 && back == -1) {
			front = 0; 
			back = 0;
			arr[0] = val;
			return; 
		}
		
		else if (direction == 'f') {
			front = (front - 1) % MAX; //pushing into front 
			arr[front] = val; 
		}
		else {
			back = (back + 1) % MAX; // pushing into back 
			arr[back]= val;
		}
		//printArr();
		return; 
	}

	int remove(char direction) {
		int ret = 0;
		if (front == 0 && back == 0) { //**********
			front = -1;
			back = -1; 
			arr[0] = 255; 
			return -1;
		}
		else if (direction == 'f') {
			ret = arr[front];
			arr[front] = 255;
			front = (front + 1) % MAX; // removing from front 
			//printArr();
			return ret; 
		}
		else {
			ret = arr[back];
			arr[back] = 255;
			if (back == 0) back = MAX - 1; //**********
			else back = (back - 1) % MAX; // removing from back
			//printArr();
			return ret;
		}

		cout << "Error Case" << endl; 
		return -1; 
	}

	void printArr() {
		cout << "FRONT = " << front << " AND BACK = " << back << endl;
		for (int i = 0; i < MAX; ++i) {
			cout << arr[i] << " "; 
			cout << endl; 
		}
	}
}; 

int main() {
	myClass c1; 
	//do whatever user wants here!
	c1.insert(10, 'b');
	c1.insert(20, 'b');
	c1.insert(30, 'b');
	c1.insert(40, 'b');
	int removed = c1.remove('f'); 
	cout << "removed value " << removed << " from array." << endl;

	c1.insert(50, 'b');
	c1.insert(60, 'b');
	c1.remove('b');
	c1.insert(70, 'f');
	removed = c1.remove('b');
	cout << "removed value " << removed << " from array." << endl;

	c1.printArr(); 
	return 0; 
}