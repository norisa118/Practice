// Functions: push(), pop(), constructor(), top() 
//implement with ints first and then change to template
// not cnosidering a max size -- Should I be ? Overflow?
//Heapify ? Internal nodes from R to L? 


//if parent is at index i, then:
	//LEFT CHILD: 2i+1
	//RIGHT CHILD: 2i+2

//Parent Index: (i-1)/2

// CAPACITY AND SIZE NOT IMPLEMENTED IN THIS AS I USED VECS NOT ARR



class Heap {
	//constructor: 
	Heap(vector<int> vec_In) {
		//given a vector? 
		for (auto iter = vec_In.begin(); iter != vec_In.end(); ++iter) {
			heapRep.push_back(*iter);
		}
		update_Push();
	}

	//top(): 
	int top() {
		return heapRep[0];
	}

	//empty(): 
	bool empty() {
		return (heapRep.empty());
	}


	//push():
	void push(int val_In) {
		//if maxsize implemented, check that here
	
		//push it in 
		heapRep.push_back(val_In); 

		//update heap properties:
		update_Push();
	}

	//update_Push():
	void update_Push() {
		//check with parent, if parent < current, swap current and parent --> do till you reach the root node. 
		for (int i = heapRep.size(); i != 0; i = (i - 1) / 2) {
			if (heapRep[(i - 1 / 2)] < heapRep[i]) std::swap(heapRep[i], heapRep[(i - 1 / 2)])
		}
	}
	
	//pop(): 
	int pop(){
		if (heapRep.empty()) return -10000; // hardcoded for now 
		//store max: 
		int max = heapRep.top(); 

		//swap topmost and bottom leftmost element:
		std::swap(heapRep[0], heapRep[heapRep.size() - 1]); // do I need to case heapRep.size() to int? 

		// actually delete the now bottom leftmost element (min or max)
		heapRep.pop_back();

		//update heap properties:
		update_Pop();
		return max; 
	}

	//update_Pop():
	void update_Pop() {
		//left child is 2i+1, right child is 2i+2 
		if (heapRep[0] < heapRep[i]) {
			//left side case:
			for (int i = 0; i != heapRep.size()-1; i = 2i+1) {
				if (heapRep[i] < heapRep[2i+1]) std::swap(heapRep[i], heapRep[2i+1])
			}

		}
		else if (heapRep[0] < heapRep[2]) {
			//right side case
			for (int i = 0; i != heapRep.size(); i = 2i+2) {
				if (heapRep[i] < heapRep[2i + 2]) std::swap(heapRep[i], heapRep[2i + 2])
			}
		}
		else {
			cout << "update_Pop(): not left or right casse" << endl; 
			return;
		}
	}


	// debug():
	void debug() {
		//print heap: 
	}
private:
	vector<int> heapRep;
};

int main() {
	//create a class object: 
	Heap([1, 7, 16]); 

}