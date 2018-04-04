/* *题目：
 *  判断一颗二叉树是不是对称的
 * *思路：
 *  
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL){
            return true;
        }
        
        return isSys(pRoot->left, pRoot->right);
    }
    
    bool isSys(TreeNode* ltree, TreeNode* rtree){
        if(ltree == NULL && rtree == NULL){
            return true;
        }
        
        if(ltree != NULL && rtree != NULL){
            return ltree->val == rtree->val && isSys(ltree->left, rtree->right) && isSys(ltree->right, rtree->left);
        }
        
        return false;
    }
};