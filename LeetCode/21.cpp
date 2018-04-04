/* *题目：
 *  21
 *  Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //每次在两个链表中找最小的
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        while(pl1 != NULL || pl2 != NULL){
            if(pl1 == NULL){
                p->next = pl2;
                pl2 = pl2->next;
            }else if(pl2 == NULL){
                p->next = pl1;
                pl1 = pl1->next;
            }else{
                if(pl1->val < pl2->val){
                    p->next = pl1;
                    pl1 = pl1->next;
                }else{
                    p->next = pl2;
                    pl2 = pl2->next;
                }
            }
            p = p->next;
        }
        p = head->next;
        delete head;
        return p;
    }
};