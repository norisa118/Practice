class Solution {
public:
//semi-optimized
//norisa
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dpTbl(n+1);
        for(int i =0; i < n+1; ++i){
            dpTbl[i].resize(amount+1);
        }
      
        
        int answer = knapsack(coins, amount, n);
        if(answer == INT_MAX-1) return -1;
        return answer; 
    }
    
    int knapsack(vector<int>& coins, int amount_remaining, int n){
        int dpTbl[n+1][amount_remaining+1]; 
        //BASE CASE:
    for(int i=0; i < n+1; ++i){
        dpTbl[i][0] = 0;
    }

    for(int j=1; j< amount_remaining+1; ++j){
        dpTbl[0][j] = INT_MAX-1;
    }

    //DP STEP: 
    for(int i = 1; i < n+1; ++i){
        for(int j=1; j< amount_remaining + 1; ++j){
            if(j - coins[i-1] >= 0){
                //pick
                int op1 = 1+dpTbl[i][j-coins[i-1]];
                //don't pick
                int op2 = dpTbl[i-1][j];
                dpTbl[i][j] = min(op1,op2);
            } else{
                // dont pick
                dpTbl[i][j]= dpTbl[i-1][j];
            }
        }
    }
 

    return dpTbl[n][amount_remaining];
    }
    
};