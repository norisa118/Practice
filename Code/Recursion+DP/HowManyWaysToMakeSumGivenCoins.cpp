#include<iostream>
#include<algorithm>
#include <vector>
#include <bits/stdc++.h>


using namespace std; 


// Coin Change on Leetcode, except count the number of ways that we can sum up to target sum : --> Oh, turns out this is coin change 2

    int knapsack(vector<int>& coins, int amount_remaining, int n){
            int dpTbl[n+1][amount_remaining+1]; 
            //BASE CASE:
        for(int i=0; i < n+1; ++i){
            dpTbl[i][0] = 1;
        }

        for(int j=1; j< amount_remaining+1; ++j){
            dpTbl[0][j] = 0;
        }

        //DP STEP: 
        for(int i = 1; i < n+1; ++i){
            for(int j=1; j< amount_remaining + 1; ++j){
                if(j - coins[i-1] >= 0){
                    //pick
                    int op1 = dpTbl[i][j-coins[i-1]];
                    //don't pick
                    int op2 = dpTbl[i-1][j];
                    dpTbl[i][j] = op1 + op2; // THIS SHOULD CHANGE THO 
                } else{
                    // dont pick
                    dpTbl[i][j]= dpTbl[i-1][j];
                }
            }
        }
    

        return dpTbl[n][amount_remaining];
    }


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
    
    
    int main(){
        std::vector<int> v { 1,2,5 };
        int answer = coinChange(v, 5);
        cout << answer << endl; 
        return answer; 
    }
