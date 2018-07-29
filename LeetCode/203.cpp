/* *题目：
 *  203
 *  Remove Linked List Elements
 *  
 */

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *curr;
        ListNode *first = new ListNode(0);
        first->next = head;
        prev = first;
        curr = head;
        
        while(curr != NULL){
            if(curr->val == val){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        head = first->next;
        delete first;
        return head;
    }
};