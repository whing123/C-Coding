/* *题目：
 *  二叉搜索树第k个节点
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        return Kth(pRoot, k);
    }
    
    TreeNode* Kth(TreeNode* pRoot, int& k){
        if(pRoot == NULL){
            return NULL;
        }
        
        TreeNode* res = Kth(pRoot->left, k);
        if(k == 0) return res;
        if(--k == 0) return pRoot;
        return Kth(pRoot->right, k);
    }
    
};