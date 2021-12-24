// SAME as TokenizeByAnything.cpp but using the strtok from the STL:
// MISTAKES MADE: Everything has to be char name [] = " "; format
#include <string.h>
#include <iostream>
#include<vector>
using namespace std;

vector<string> tokenizer(char* str, char* delim) { 
    // Returns first token 
    char* token = strtok(str, delim);
    vector<string> retVec;
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        retVec.push_back(token);
        token = strtok(NULL, delim);
    }

    return retVec; 
}

int main() {
    char line[] = "Geeks for Geeks";
    char space[] = " ";
    vector<string> returned = tokenizer(line, space);
    for (size_t i = 0; i < returned.size(); i++) {
        cout << returned[i] << endl;
    }
	return 0;
}