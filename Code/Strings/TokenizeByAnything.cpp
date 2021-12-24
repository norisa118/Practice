#include <string>
#include <vector>
#include<iostream>

// errors made: forgot to clear the temp string & at END of sentence, no ',' or ' ' or ':', so it wasn't reading the last word --> the fix: 
// 

using namespace std;

vector<string> tokenizer(string str) { //add char del.
	vector<string> retVec = {};
	string newMade = "";

	//read str char by char: NOTE THAT THIS IS THE BEST WAY TO DO THIS TIME/SPACE WISE
	for (auto it = str.begin(); it != str.end(); it++) {

		// if char is != ( : and , and space) 
		if (*it != ':' && *it != ' ' && *it != ',' && (*it != '\0')) {
			//concatenate string into newMade: 
			newMade.push_back(*it);
		}

		else {
			//push newly made string into box and move on: 
			retVec.push_back(newMade);
			cout << newMade << endl;
			// CLEAR NEWMADE:
			newMade = "";
		}
	}

	return retVec;
}

int main() {
	string line = "GeeksForGeeks,     is a must try"; // works with : or space or whatevs at end, not without tho
	vector<string> returned = tokenizer(line);
	for (size_t i = 0; i < returned.size(); i++) {
		cout << returned[i] << endl;
	}
	return 0;
}