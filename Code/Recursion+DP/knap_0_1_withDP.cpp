#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int dpTbl[10+1][5+1]; // w_remaining rows and n columns, but we want +1 on both rows and cols.(title naming for first row and col)


int knapsack(int* weights, int* vals, int w_remaining, int n){
    int opt_Val_1 = 0;
    int opt_Val_2 = 0;

    //BASE CASE: 
    if(n == 0 || w_remaining == 0) return 0; 

    // 3. CHECK if the subproblem has been solved:
    if(dpTbl[w_remaining][n]!=-1){
        return dpTbl[w_remaining][n];
    } 

    //RECURSE: 
     if(w_remaining - weights[n-1] >= 0){
        //PICKING IT: 
        opt_Val_1 = vals[n-1] + knapsack(weights, vals,  w_remaining - weights[n-1], n-1);
        opt_Val_2 = knapsack(weights, vals, w_remaining, n-1);
        return dpTbl[w_remaining][n] = max(opt_Val_1, opt_Val_2);
    } else{
        return dpTbl[w_remaining][n]= knapsack(weights, vals, w_remaining, n-1);
    }


    dpTbl[w_remaining][n] = max(opt_Val_1, opt_Val_2);  // 1. Insead of returning, store the value in dpTbl
    return dpTbl[w_remaining][n]; // 2. Return what you just stored in dpTbl form

}

int main(){
    memset(dpTbl, -1, sizeof(dpTbl)); 
    //make a weights arr: 
    int weights_Arr[] = {1,6,3,10,5};
    //make a values array:
    int values_Arr[] = {1,9,3,3,15}; 
    //make a capacity: 
    const int capacity = 10; 
    int answer = knapsack(weights_Arr, values_Arr, capacity, 5); 
    cout << "Answer: " << answer << endl; 
    return 0;
}