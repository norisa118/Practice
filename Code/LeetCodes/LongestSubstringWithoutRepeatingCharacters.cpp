class Solution {
public:
    //BRUTE FORCE
    //norisa
    int lengthOfLongestSubstring(string s) {
        //traverse through every character:
        std::map<char,int> tempMap;
        int tempMax = 0;
        int retMax = 0; 
        for(int i = 0; i < s. length(); i++){
            // from ch_Init to the rest of the string s:
            for(int j = i; j < s. length(); j++){
            //find the max length of unique characters FROM this character: 
                //make a TEMP map
                map<char,int>::iterator it;
                it = tempMap.find(s[j]);

                // we just wanna store the CURRENT MAX LENGTH as the global variable
                if(it == tempMap.end()){
                    tempMap[s[j]] = 1; // element does not exist, so add it in
                    tempMax++;
                }
            
                else{
                    // elem does already exist, hence duplicate
                    break;
                } // end of else
            
        }  // end of inner for loop
        // clear map: 
        tempMap.clear(); 
            
        if(tempMax > retMax) retMax = tempMax; 
        tempMax=0;
        } // end of largest for loop
        return retMax;
    }
};