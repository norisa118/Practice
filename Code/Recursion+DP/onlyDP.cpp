#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int t[5+1][10+1]; // w_remaining rows and n columns, but we want +1 on both rows and cols.(title naming for first row and col)


int knapsack(int* weights, int* vals, int w, int n){

    //BASE CASE:
    for(int i=0; i < n+1; ++i){
        t[i][0] = 0;
    }

    for(int j=0; j< w+1; ++j){
        t[0][j] = 0;
    }

    //DP STEP: 
    for(int i = 1; i < n+1; ++i){
        for(int j=1; j<w+1; ++j){
            if(j - weights[i-1] >= 0){
                //pick
                int op1 = vals[i-1]+t[i-1][j-weights[i-1]];
                //don't pick
                int op2 = t[i-1][j];
                t[i][j] = max(op1,op2);
            } else{
                // dont pick
                t[i][j]= t[i-1][j];
            }
        }
    }
 

    return t[n][w];
}


int main(){
    memset(t, -1, sizeof(t)); 
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