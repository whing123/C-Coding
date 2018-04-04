/* *题目：
 *  129
 *  Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int res = 0;
        int path = 0;
        
        sumHelper(root, path, res); 
        
        return res;
    }
    
    void sumHelper(TreeNode* root, int & path_sum, int & res){
        if(root == NULL){
            return;
        }
        
        path_sum = path_sum * 10 + root->val;
        
        if(root->left == NULL && root->right == NULL){
            res += path_sum;
        }

        sumHelper(root->left, path_sum, res); 
        sumHelper(root->right, path_sum, res);
        
        path_sum -= root->val;
        path_sum /= 10;
    }
};