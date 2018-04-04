/* *题目：
 *  判断平衡二叉树
 * *思路：
 *  
 */

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL){
            return true;
        }
        
        return abs(height(pRoot->left) - height(pRoot->right)) <= 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    
    // 求树高
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + (lh > rh ? lh : rh);
    }
};