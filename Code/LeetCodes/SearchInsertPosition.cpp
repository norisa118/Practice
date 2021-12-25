class Solution {
    // BRUTE FORCE
    // norisa
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0 ; i < nums.size() ; i++){  
            if(nums[i] == target) return i; 
            
            
            if(nums[nums.size()-1] < target){
                return nums.size(); 
            }
            
            if(nums[i] < target && nums[i+1] > target){
                return i+1;
            }
            
            
        } //end of for
        
      return 0;   
    }
};