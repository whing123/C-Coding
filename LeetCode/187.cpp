/* *题目：
 *  2
 *  Add Two Numbers
 * *思路：
 *  
 * *技法：
 *  
 */

 /**
  Definition for singly-linked list.

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 **/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *result = NULL, *rear = NULL;
        int sum, d;
        
        d = 0;
        while(p1 != NULL && p2 != NULL)
        {
            sum = p1->val + p2->val + d;
            if(sum / 10 != 0)
            {
                d = 1;
            }
            else
            {
                d = 0;
            }
            
            if(rear == NULL)
            {
                rear = result = new ListNode(sum % 10);
            }
            else
            {
                rear->next = new ListNode(sum % 10);
                rear = rear->next;
            }
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(p1 == NULL && p2 == NULL)
        {
            if(d == 1)
            {
                rear->next = new ListNode(d);
                rear = rear->next;
            }
        }
        else if(p1 == NULL)
        {
            while(p2 != NULL)
            {
                sum = p2->val + d;
                if(sum / 10 != 0)
                {
                    d = 1;
                }
                else
                {
                    d = 0;
                }
                rear->next = new ListNode(sum % 10);
                rear = rear->next;
                
                p2 = p2->next;
            }
            if(d != 0)
            {
                rear->next = new ListNode(d);
                rear = rear->next;
            }
        }
        else if(p2 == NULL)
        {
            while(p1 != NULL)
            {
                sum = p1->val + d;
                if(sum / 10 != 0)
                {
                    d = 1;
                }
                else
                {
                    d = 0;
                }
                rear->next = new ListNode(sum % 10);
                rear = rear->next;
                
                p1 = p1->next;
            }
            if(d != 0)
            {
                rear->next = new ListNode(d);
                rear = rear->next;
            }
        }
        
        return result;
    }
};