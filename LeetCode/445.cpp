/* *题目：
 *  445
 *  Add Two Numbers II
 * *思路： 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1, num2;
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        
        //置入栈中
        while(tmp1 != NULL){
            num1.push(tmp1->val);
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL){
            num2.push(tmp2->val);
            tmp2 = tmp2->next;
        }
        
        ListNode *head = new ListNode(0);  // 头结点
        ListNode *tmp;
        int sum = 0;
        int carry = 0;
        while(!num1.empty() || !num2.empty()){
            if(!num1.empty() && !num2.empty()){  // 两个栈都不空
                sum = num1.top() + num2.top() + carry;
                carry = sum / 10;
                sum %= 10;
                num1.pop();
                num2.pop();
            }else if(!num1.empty()){ // 1不空2空
                sum = num1.top() + carry;
                carry = sum / 10;
                sum %= 10;
                num1.pop();
            }else{  // 1空2不空
                sum = num2.top() + carry;
                carry = sum / 10;
                sum %= 10;
                num2.pop();
            }
            
            //插入头结点之后
            tmp = new ListNode(sum);
            tmp->next = head->next;
            head->next = tmp;
        }
        
        //补上进位
        if(carry){
            tmp = new ListNode(carry);
            tmp->next = head->next;
            head->next = tmp;
        }
        
        tmp = head->next;
        delete head;
        return tmp;
    }
};