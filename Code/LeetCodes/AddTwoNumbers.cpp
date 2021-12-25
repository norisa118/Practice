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
    //Semi-Optimized
    //norisa
  public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
        ListNode* newList = new ListNode(); // newList is just pointing to empty space.
        ListNode* moveHead = newList; // this is a pointer to the newList
        int sum = 0;
        int carry = 0; 
        while(l1!=nullptr || l2!=nullptr){
            sum = 0;
            //ONE of them may be null tho: 
            if(l1!=nullptr) sum = sum + l1->val;
            if(l2!=nullptr) sum = sum + l2->val;
            sum = sum + carry;
            carry = sum/10; 
            moveHead->next = new ListNode(sum%10); //now list has first element 
            moveHead = moveHead->next;
            if(l1 !=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next; 
        }
        
        // AFTER both are complete, if we still have a carryover: 
        if(carry == 1){
            moveHead->next = new ListNode(1);
        }
        
        return newList->next; //NOT newList bc head is POINTING to rest of the answer. Head is not part of answer
    }
};