#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

template <class T>
class myClass {
public:
	//empty global queue with deque:
	deque<T> my_q;

	void gather() {
		string inserted; 
		cout << "Insert a string of items: " << endl; 
		getline(cin, inserted);

		// stringstream class check1
		stringstream check1(inserted);

		string intermediate;

		// Tokenizing w.r.t. space ' '
		while (getline(check1, intermediate, ' '))
		{
			my_q.push_back(intermediate);
		}



		/*place items into queue 
		for (auto i: inserted) {
			T ia; 
			ia = i;  // this is a problem here 
			my_q.push_back(ia);
		}*/ 

	}

	void printCombos() {
		// print initial queue:
		print_forward(my_q);
		//rest of rotations and prints:
		for (int i = 0; i < my_q.size() - 1; ++i) {

			//rotate:
			my_q.push_back(my_q.front());
			my_q.pop_front();
			//print:

			print_forward(my_q);
			/*while (!my_q.empty())
			{
				std::cout << ' ' << my_q.front();
				my_q.pop();
			}*/
		}
	}

	void print_forward(deque<T> const &deque) // why is it const & ?
	{
		for (auto it = deque.cbegin(); it != deque.cend(); ++it) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}

	/*T convert_to(const std::string &str)
	{
		std::istringstream ss(str);
		T num;
		ss >> num;
		return num;
	}*/

}; 

int main() {
	myClass<string> c1;
	c1.gather();
	c1.printCombos();
	return 0; 
}