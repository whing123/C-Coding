/* *题目：
 *  148
 *  Sort List
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
    //merge two sorted list, return result head
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1 == NULL){
            return h2;
        }
        if(h2 == NULL){
            return h1;
        }
        
        if(h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else{
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        //bottom case
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        
        //p1 move 1 step every time, p2 move 2 step every time, pre record node before p1
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* pre = head;
        
        while(p2 != NULL && p2->next != NULL){
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //change pre next to null, make two sub list(head to pre, p1 to p2)
        pre->next = NULL;
        
        //handle those two sub list
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(p1);
        
        return merge(h1, h2);
        
    }
};

// java
public class Solution {
  
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
          return head;
            
        // step 1. cut the list to two halves
        ListNode prev = null, slow = head, fast = head;
        
        while (fast != null && fast.next != null) {
          prev = slow;
          slow = slow.next;
          fast = fast.next.next;
        }
        
        prev.next = null;
        
        // step 2. sort each half
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(slow);
        
        // step 3. merge l1 and l2
        return merge(l1, l2);
    }
  
    ListNode merge(ListNode l1, ListNode l2) {
        ListNode l = new ListNode(0), p = l;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        
        if (l1 != null)
            p.next = l1;
    
        if (l2 != null)
            p.next = l2;
    
        return l.next;
    }

}