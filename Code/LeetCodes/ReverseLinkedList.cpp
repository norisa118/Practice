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
    //semi-optimized
    //norisa
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  
        
        while(head!=nullptr){
            ListNode* next = head->next; //next = 2 (storing before we change)
            head->next = prev; // 1-> null -> 2 -> 3.... 
            //head is still 1. 
            prev = head; //(so now prev is storing 1)
            head = next; //making 2 into the head
        }
        
        return prev;
    }
};