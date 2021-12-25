class Solution {
    
public:
    //optimized 
    //norisa
    int maxProfit(vector<int>& prices) {
     if(prices.size() <= 1){
            return 0;
        }
        
        int minPrice = INT_MAX; //max the min price can be       
        int maxSum = 0; //this is the min the max Sum can be 
        
        for(int i = 0; i < prices.size(); i++){
    
          if(prices[i] < minPrice){
                minPrice = prices[i];
            }else if(prices[i] - minPrice > maxSum){
                maxSum = prices[i] - minPrice;
            } 
            
        }
        return maxSum;
    }
};