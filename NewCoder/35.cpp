/* *题目：
 *  二叉树的深度
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
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot){
            int lh = TreeDepth(pRoot->left);
            int rh = TreeDepth(pRoot->right);
             
            return (lh > rh ? lh : rh) + 1;
        }
         
        return 0;
    }
};