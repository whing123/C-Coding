/* *题目：
 *  563
 *  Binary Tree Tilt
 * *思路：
The tilt of a tree node is defined as the absolute difference 
between the sum of all left subtree node values and the sum of all right subtree node values
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
    int findTilt(TreeNode* root) {
        int sum = 0;
        travTree(root,sum);
        return sum;
    }
    
    void sumTree(TreeNode* root, int &sum){
        if(root == NULL){
            return ;
        }
        
        sum += root->val;
        sumTree(root->left,sum); sumTree(root->right,sum);
    }
    
    void travTree(TreeNode* root, int &sum){
        if(root == NULL){
            return ;
        }
        
        int val_left = 0, val_right = 0;
        sumTree(root->left, val_left);
        sumTree(root->right, val_right);
        
        sum += abs(val_left - val_right);  //该节点左右子树之差
        
        travTree(root->left, sum); travTree(root->right, sum);
    }
};