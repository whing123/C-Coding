/* *题目：
 *  从尾到头打印链表
 * *思路：
 *  
 */

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

// 栈 
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p = head;
        
        stack<int> tmp;
        while(p){
            tmp.push(p->val);
            p = p->next;
        }
        
        vector<int> res;
        while(!tmp.empty()){
            res.push_back(tmp.top());
            tmp.pop();
        }
        
        return res;
    }
};

// 递归
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head){
            printListFromTailToHead(head->next);
            res.push_back(head->val);
        }
        
        return res;
    }
    
    vector<int> res;
};

// better
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        
        printList(head, res);
        
        return res;
    }
    
    void printList(ListNode* head, vector<int>& res){
        if(head){
            printList(head->next, res);
            res.push_back(head->val);
        }
    }
};