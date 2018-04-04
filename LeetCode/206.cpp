/* *题目：
 *  206
 *  Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode * new_head = new ListNode(0), *tmp;
        new_head->next = head;
        while(head->next){
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = new_head->next;
            new_head->next = tmp;
        }
        head = new_head->next;
        delete new_head;
        return head;
    }
};