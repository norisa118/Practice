#include <thread> 
#include <iostream>

using namespace std; 

	int addition() {
		cout << 10 + 20 << " " << endl;
	}

	int multiplication() {
		cout << 10 * 20 << " " << endl;
	}


int main() {
	thread t1(addition);
	cout << " done1 " << endl;
	thread t2(multiplication);
	cout << " done2 " << endl;

	if (t1.joinable() && t2.joinable()) {
		t1.join();
		t2.join();
	}
	cout << " Done. " << endl; 
	return 0; 
}