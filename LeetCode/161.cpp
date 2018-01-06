/* *题目：
 *  382
 *  Linked List Random Node
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
private:
    vector<int> nums;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *tmp = head;
        while(tmp != NULL){
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        srand(unsigned(time(0)));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */