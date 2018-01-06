/* *题目：
 *  112
 *  Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
       int add = 0;
       return  hasPath(root,sum,add);
    }
    
    bool hasPath(TreeNode* root, int sum, int& add){
        if(root == NULL){
            return false;
        }
        add += root->val;
        if(root->left == NULL && root->right == NULL){  // leaf node
            if(add == sum){
                return true;
            }else{
                add -= root->val;
                return false;
            }
        }
        if(hasPath(root->left,sum,add) || hasPath(root->right,sum,add)){
            return true;
        }
        add -= root->val;
        return false;
    }
};