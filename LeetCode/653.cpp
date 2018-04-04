/* *题目：
 *  653
 *  Two Sum IV - Input is a BST
 * *思路：
 *  
 * *技法：
 *  
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> table;
        return search(root, table, k);
    }
    
    bool search(TreeNode* root, unordered_set<int>& sets, int k){
        if(root == NULL){
            return false;
        }
        
        if(sets.count(k - root->val)){  // check if k-a exists
            return true;
        }
        
        sets.insert(root->val);
        
        return search(root->left, sets, k) || search(root->right, sets, k);
    }
};