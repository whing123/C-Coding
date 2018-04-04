/* *题目：
 *  二叉树子结构判断
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL){
            return false;
        }
            
        if(isSame(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)){
            return true;
        }
        
        return false;    
    }
    
    // 子结构相同
    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == NULL && pRoot2 == NULL || pRoot1 != NULL && pRoot2 == NULL){ // 第二个判断是重点
            return true;
        }else if(pRoot1 == NULL && pRoot2 != NULL){
            return false;
        }
        
        return pRoot1->val == pRoot2->val && isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }
};