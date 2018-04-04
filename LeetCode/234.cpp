/* *题目：
 *  234
 *  Palindrome Linked List
 * *思路：
 *  
 * *技法：
 *  
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
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* tmp = head;
        while(tmp != NULL){
            values.push_back(tmp->val);
            tmp = tmp->next;
        }
        int size = values.size();
        for(int i = 0;i < size / 2;i++){
            if(values[i] != values[size-1-i])
                return false;
        }
        return true;
    }
};