/* *题目：
 *  109
 *  Convert Sorted List to Binary Search Tree
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> List;
        ListNode* tmp = head;
        while(tmp){
            List.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        return makeTree(List); 
    }
    
    TreeNode* makeTree(vector<int>& vec){
        if(vec.size() == 0){
            return NULL;
        }
        
        int mid = vec.size() / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        
        vector<int> ltree(vec.begin(), vec.begin()+mid);
        root->left = makeTree(ltree);
        
        vector<int> rtree(vec.begin()+mid+1, vec.end());
        root->right = makeTree(rtree);
        
        return root;
    }
};