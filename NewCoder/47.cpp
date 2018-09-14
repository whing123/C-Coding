/* *题目：
 *  合并两个排序的链表
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
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(-1); // 伪头节点
        ListNode* cur = head;
        
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            
            cur = cur->next;
        }
        
        if(pHead1 == NULL){
            cur->next = pHead2;
        }
        if(pHead2 == NULL){
            cur->next = pHead1;
        }
        
        cur = head->next;
        delete head;
        
        return cur;
    }
};


// 递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL){
            return pHead2;
        }
        if(pHead2 == NULL){
            return pHead1;
        }
        
        if(pHead1->val <= pHead2->val){
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        
        if(pHead1->val > pHead2->val){
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
        
        return NULL;
    }
};