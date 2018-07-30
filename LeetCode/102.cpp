/* *题目：
 *  102
 *  Binary Tree Level Order Traversal
 * *思路：
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

// better
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            int size = level.size();
            vector<int> tmp(size, 0);
            
            while(size--){
                TreeNode* node = level.front();
                level.pop();
                tmp[(tmp.size()-1) - size] = node->val;
                
                if(node->left){
                    level.push(node->left);
                }
                if(node->right){
                    level.push(node->right);
                }
            }
            
            result.push_back(tmp);
        }
        
        return result;
    }
};
