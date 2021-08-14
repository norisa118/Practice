#include <iostream>
#include <unistd.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

class myClass {
public:
	print_Nums() {
		for (int i = 1; i < 11; ++i) {
			cout << i << endl; 
			sleep(5);
		}
	}
};




int main() {
	myClass classInst;
	int pid2 = fork();
	if (pid2 == -1) {
		cout << "error" << endl; 
	}
	else if (pid2 > 0) {
		// we are in the parent process
		cout << "Parent PID: " << getpid() << endl;
	}
	else {
		// PID = 0 means we are in the child process 
		cout << "Child PID: " << getpid() << endl;
	}

	classInst.print_Nums(); 

	return 0;
}



