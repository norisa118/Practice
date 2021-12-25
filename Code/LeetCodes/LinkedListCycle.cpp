/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //semi-optimized
    //norisa
    bool hasCycle(ListNode *head) {
        //is there a loop or nah is the question :D 
        if(head == nullptr) return false; 
        ListNode* slow = head; 
        ListNode* fast = head->next;
        
        while(slow !=fast){
            if(fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next; 
            fast = fast->next->next; 
        }
        
        return true;
    }
};