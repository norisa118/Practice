class Solution {
    //OPTIMIZED
    //norisa
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> retVec;

        int difference = 0;
        unordered_map<int, int>::iterator it;

        //Go through every elem in the given vec:
        for(int i =0; i < nums.size(); ++i){
            //Calculate difference: Target Val - Elem Val:
            difference = target - nums[i]; 
            //If map contains difference val, AND index of diff val is not equal to index of elem val:
            it = myMap.find(difference);
            if(it!=myMap.end() && it->second != i){
                //We have solution → Return the two indices
                retVec.push_back(it->second);
                retVec.push_back(i);
                return retVec;
            }
            //Else: Store elem and index in the map:
            else{
                myMap.insert({nums[i], i});
            }
        }
        
        return retVec; //empty
    }
};