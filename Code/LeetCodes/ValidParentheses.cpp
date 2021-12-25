class Solution {
    //BRUTE FORCE
    //norisa
public:
    stack<char> mystack;

   		bool isValid(string s) {
		//push in until ')' or ']' or '}' is encountered: 
		bool found = false;
		if (s == "") return false;
		for (char c : s) {
			cout << "coming back here" << endl; 
			found = false;
			if (c != ')' && c != '}' & c != ']') mystack.push(c);
			//')' or ']' or '}' is enountered: 
			else {
				while (!mystack.empty()) {
					if ((c == ')' && mystack.top() == '(') || (c=='}' && mystack.top() == '{') || (c==']' && mystack.top() == '[')) {
						cout << "making found into true here and popping the following" << mystack.top() << endl; 
						found = true;
						mystack.pop();
						break;
					}
					else break; 
				}
				cout << "found is " << found << endl; 
				if (!found) return false;
			}
			cout << "coming here" << endl;
		}


		while (!mystack.empty()) {
			cout << "coming into while" << endl; 
			if (!mystack.empty()) {
				if (mystack.top() == '(' || mystack.top() == ')' || mystack.top() == '{' || mystack.top() == '}' || mystack.top() == '[' || mystack.top() == ']') {
					return false;
				}
				else {
					mystack.pop();
				}
			}
			cout << "exiting out of while" << endl; 
		}

		return true;
	}
};