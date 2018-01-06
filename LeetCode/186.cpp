/* *题目：
 *  142
 *  Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            if(slow == fast)
                break;
        }
        if(fast == NULL)
            return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};