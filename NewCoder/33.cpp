/* *题目：
 *  删除链表中重复的结点
 * *思路：
 *  
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL){
            return NULL;
        }
         
        ListNode *start, *prev, *p, *head;
         
        // 伪头节点
        head = new ListNode(-1);
        head->next = pHead;
        prev = head;
        p = pHead;
         
        while(p != NULL){
            start = p; // 当前起始节点
            while(p->next != NULL && p->val == p->next->val){
                p = p->next;
            }
             
            if(start == p){ // 没有移动的话
                prev = p;
                p = p->next;
            }else{ // 有移动的话
                ListNode* end = p; // 要删除的最后一个节点
                p = p->next;
                prev->next = p;
                 
                // delete 重复节点
                end->next = NULL;
                while(start != NULL){
                    ListNode* tmp_ = start;
                    start = start->next;
                    delete tmp_;
                }
            }
        }
         
        ListNode* tmp = head->next;
        delete head; // 删除伪头节点
        return tmp;
    }
};