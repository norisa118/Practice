/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    //Optimized
    //norisa
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head; 
        while(current != nullptr && current->next != nullptr){
           //if the current node = next node, then skip over the next node:
            if(current->val == current->next->val){
                current->next = current->next->next; 
            } //end of inner if
            else{
               current = current->next;  
            } //end of else
        } //end of while loop
        
        return head; 
    }
};