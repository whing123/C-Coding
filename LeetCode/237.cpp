/* *题目：
 *  237
 *  Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
        ListNode *node_next = node->next;
        node->val = node_next->val;
        node->next = node_next->next;
        delete node_next;
    }
};