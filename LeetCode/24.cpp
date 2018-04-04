/* *题目：
 *  24
 *  Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p, *q, *z, *pre, *newhead = new ListNode(0);
        pre = newhead;
        pre->next = head;
        p = q = z = head;
        while(p){
            q = p->next;
            if(q == NULL){
                return newhead->next;
            }
            z = q->next;
            p->next = z;
            q->next = p;
            pre->next = q;
            //move
            pre = pre->next;
            pre = pre->next;
            p = pre->next;
        }
        pre = newhead;
        newhead = newhead->next;
        delete pre;
        return newhead;
    }
};