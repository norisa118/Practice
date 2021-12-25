/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //Semi-Optimized
    //norisa
public:
    int maxDepth(TreeNode* root) {
    //basic init:
    
        if(!root) return 0; //no root case 
        
    //actual code:
        
        int leftDepth = 0;
        int rightDepth = 0;
        leftDepth = 1+ maxDepth(root->left); // if the left exists add 1
        rightDepth = 1+maxDepth(root->right); //if the right exists add 1
        
        //initially we add to 1 because of the root counting as 1. 
        //finally return maximum of left and right since we want MAX depth 
        return max(leftDepth,rightDepth);
    }
};