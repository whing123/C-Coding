/* *题目：
 *  反转链表
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

// 递归
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL){
            return NULL;
        }
        
        // 伪头节点
        ListNode* p, *res;
        p = res = new ListNode(0);
        
        Reverse(pHead, res);
        
        // 末尾指向
        if(res->next){
            res->next = NULL;
        }
        
        res = p->next;
        delete p;
        
        return res;
    }
    
    void Reverse(ListNode* pHead, ListNode*& res){
        if(pHead != NULL){
            Reverse(pHead->next, res);
            res->next = pHead;
            res = res->next;
        }
    }
};

// 常规
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL){
            return NULL;
        }
        
        // 伪头节点
        ListNode* p;
        p = new ListNode(0);
        p->next = pHead;
        pHead = pHead->next;
        p->next->next = NULL; // 末尾置NULL
        
        while(pHead){
            ListNode* tmp = pHead;
            pHead = pHead->next;
            
            // 插入伪头节点后
            tmp->next = p->next;
            p->next = tmp;
        }
        
        ListNode* res = p->next;
        delete p;
        
        return res;
    }
};