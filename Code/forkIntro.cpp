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
	pid_t pid = getpid();
	//printf("pid: %lun", pid);
	cout << "PID: " << pid << endl; 
	classInst.print_Nums(); 
	//children create:
	//int pid2 = fork();
	//int pid3 = fork();
	return 0;
}



