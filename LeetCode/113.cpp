/* *题目：
 *  113
 *  Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
            
        if(root == NULL){
            return res;
        } 
        
        vector<int> path;
        helper(root, sum, path, res);
        
        return res;
    }
    
    void helper(TreeNode* root, int sum, vector<int> & path, vector<vector<int>>& res){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int s = 0;
            for(int i = 0; i < path.size(); ++i){
                s += path[i];
            }
            if(s == sum){
                res.push_back(path);
            }
        }
           
        helper(root->left, sum, path, res);
        helper(root->right, sum, path, res);
        
        path.pop_back();
    }
};