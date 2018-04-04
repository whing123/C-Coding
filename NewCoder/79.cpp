/* *题目：
 *  复杂链表的复制
 */

/*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        
        // 复制插入
        RandomListNode* cur = pHead;
        while(cur){
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        // 获取复制节点任意指针指向
        cur = pHead;
        while(cur){
            RandomListNode* node = cur->next;
            if(cur->random)
                node->random = cur->random->next;
            cur = node->next;
        }
        
        // 拆分
        RandomListNode* res = pHead->next;
        cur = pHead;
        while(cur->next){
            RandomListNode* tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        
        return res;
    }
};