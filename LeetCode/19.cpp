/* *题目：
 *  19
 *  Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        int i, N;
        ListNode *tmp = head, *tmp2;
        
        while(tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
        
        N = count + 1 - n;
        
        if(N == 1)
        {
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        
        i = 1;
        tmp = head;
        while(i < N)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            i++;
        }
        
        tmp2->next = tmp->next;
        delete tmp;
        return head;
        
    }
};