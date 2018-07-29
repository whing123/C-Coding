/*
  86
  Partition List
*/

/*
  将链表划分为两部分，前一部分小于x，后一部分不小于x，保持原链表相对顺序不变
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        
        // temporary head node
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* prev = tmp, *cur = head;
        
        // find break point
        while(cur){
            if(cur->val >= x){
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        
        if(cur) // there exists greater values
            while(cur->next){
                if(cur->next->val < x){ // find a node needed to be adjusted
                    ListNode* del = cur->next;
                    cur->next = del->next;

                    del->next = prev->next; // insert to the proper position
                    prev->next = del;
                    prev = prev->next; // move next to keep order
                }else{
                    cur = cur->next;
                }
            }
        
        head = tmp->next;
        delete tmp;
        
        return head;
    }
};

// better
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        
        // temporary head node
        ListNode tmp1(0);
        ListNode tmp2(0);
        ListNode* p1 = &tmp1;
        ListNode* p2 = &tmp2;
        
        while(head){
            if(head->val < x){ // less than x
                p1->next = head;
                p1 = p1->next;
            }else{ // not less than x
                p2->next = head;
                p2 = p2->next;
            }
            
            head = head->next;
        }
        
        p2->next = NULL;
        p1->next = tmp2.next;
        
        return tmp1.next;
    }
};