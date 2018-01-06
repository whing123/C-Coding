/* *题目：
 *  160
 *  Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmpA = headA, *tmpB = headB;
        int cntA = 0, cntB = 0, tmp, i = 0;
        while(tmpA != NULL)
        {
            cntA++;
            tmpA = tmpA->next;
        }
        while(tmpB != NULL)
        {
            cntB++;
            tmpB = tmpB->next;
        }
        tmp = cntA > cntB ? cntA - cntB : cntB - cntA;
        
        tmpA = headA;
        tmpB = headB;
        if(cntA > cntB){
            while(i < tmp){
                tmpA = tmpA->next;
                i++;
            }
        }else{
            while(i < tmp){
                tmpB = tmpB->next;
                i++;
            }
        }
        
        while(tmpA != tmpB){
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        
        return tmpA;
    }
};