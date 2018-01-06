/* *题目：
 *  141
 *  Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        int i = 0;
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};