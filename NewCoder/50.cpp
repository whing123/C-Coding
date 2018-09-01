/* *题目：
 *  链表中倒数第k个结点
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 求总数
        int len = 0;
        ListNode* p = pListHead;
        while(p != NULL){
            ++len;
            p = p->next;
        }
        
        // 超范围
        if(len < k){
            return NULL;
        }
        
        // 开始正数
        int cnt = len-k+1;
        p = pListHead;
        while(--cnt){
            p = p->next;
        }
        
        return p;
    }
};


// better below

/*
两个指针，先让第一个指针和第二个指针都指向头结点，然后再让第一个指针走(k-1)步，到达第k个节点。
然后两个指针同时往后移动，当第一个指针到达末尾的时候，第二个指针所在位置就是倒数第k个节点了。
*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL){
            return NULL;
        }
        
        ListNode *p, *q;
        p = q = pListHead;
        
        // 先将q移动到第k个
        int cnt = k-1;
        while(cnt--){
            q = q->next;
            if(q == NULL){ // 中途失败
                return NULL;
            }
        }
        
        // 一起往后移动，直到q到达最后一个
        while(q->next != NULL){
            q = q->next;
            p = p->next;
        }
        
        return p;
    }
};