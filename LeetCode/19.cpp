/* *题目：
 *  19
 *  Remove Nth Node From End of List

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

// better
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow, *fast, *prev, *newHead = new ListNode(0); // 伪头节点
        slow = fast = head;
        prev = newHead;
        prev->next = head;
        
        while(fast && n--){ // 先走n步
            fast = fast->next;
        }
        
        while(fast){ // 一起走
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        delete slow;
        
        head = newHead->next;
        delete newHead;
        return head;
    }
};