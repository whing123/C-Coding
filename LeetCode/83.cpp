/* *题目：
 *  83
 *  Remove Duplicates from Sorted List
 * *思路：
 *  
 * *技法：
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* curr;
        ListNode* tmp;
        
        curr = head;
        while(curr->next){
            if(curr->next->val == curr->val){
                tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
};