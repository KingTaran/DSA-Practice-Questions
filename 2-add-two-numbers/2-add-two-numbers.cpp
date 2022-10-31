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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0 ; 
        ListNode*head = new ListNode(0); 
        ListNode *t= head ; 
        while(x || l1  || l2){
            if(l1){
                x += l1 ->val ;
            }
            if(l2) {
                x += l2->val ; 
            }
            t ->next = new ListNode(x % 10); 
            t = t ->next ; 
            x = x / 10; 
            if(l1){
                l1 = l1 ->next; 
            }
            if(l2) {
                l2 = l2 ->next ; 
            }
            
        }
        return head->next == 0  ? head : head ->next ; 
    }
};