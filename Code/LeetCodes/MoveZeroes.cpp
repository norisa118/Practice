class Solution {
public:
//Brute Force
//norisa

    //if you see in place, think TWO POINTERS:
    void moveZeroes(vector<int>& nums) {
        //create 2 points: 
        int ptr1 = 0;
        int ptr2 = 0;
        for(int i=0; i< nums.size(); ++i){
            
           if(nums[ptr1]==0){ // right sees a 0, then just increment right
                          ptr1++;      
           }
            
           else{
                //swap with left: 
               std::swap(nums[ptr1], nums[ptr2]);
               //increment boht left and right pointers: 
               ptr1++;
               ptr2++; 
           }
            
        
        }
    }
};