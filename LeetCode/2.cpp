/* *题目：
 *  2
 *  Add Two Numbers
 * *思路：
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
        ListNode *p1 = l1, *p2 = l2;
        ListNode *p, *head = new ListNode(-1);
        p = head;
        
        int sum, carry = 0;
        
        while (p1 || p2) {
            if (p1 && p2) {
                sum = carry + p1->val + p2->val; 
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1) {
                sum = carry + p1->val;
                p1 = p1->next;
            } else if (p2) {
                sum = carry + p2->val;
                p2 = p2->next;
            }
            
            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
        }
        
        if (carry) {
            p->next = new ListNode(carry);
        }
        
        p = head->next;
        delete head;
        
        return p;
    }
};