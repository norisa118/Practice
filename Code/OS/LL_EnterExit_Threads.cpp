#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

//create an empty global list: 
list<int> ls;
// create mutex and condition variables: 
std::condition_variable cv; 
std::mutex m;

//function that adds 10 elements to the list: 
void add_to_list() {
	//NOTE: if i was inserting indefinitely, I'd have to check if the linked list is full.
	for (int i = 0; i < 10; ++i) {
		{
			std::lock_guard<mutex> lg(m);
			ls.push_back(i);
			cout << "Added element " << i << " to list" << endl;
		}
		sleep(1);
	}
}

//function that removes 10 elements from the list:
void remove_from_list() {
	for (int i = 0; i < 10; ++i) {
		//have to check condition as to if there is anything to remove in the first place:
		{
			cout << "waiting for mutex" << endl; 
			std::unique_lock<mutex> ul(m);
			cv.wait(ul, [] {return (ls.size() != 0) ? true : false; });

			//if condition is met, then remove elements:
			ls.pop_back();
			cout << "Removed element " << i << " from list" << endl;
		}
		sleep(1);
	}
}

int main() {
	//create two threads: 
	std::thread t1(add_to_list);
	std::thread t2(remove_from_list);
	t1.join();
	t2.join(); 
	return 0; 
}