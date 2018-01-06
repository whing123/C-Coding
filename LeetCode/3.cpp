/* *题目：
 *  617
 *  Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1 == NULL && t2 != NULL){
            t1 = t2;
            t2 = NULL;
        }
        
        tranverse(t1, t2);
        return t1;
    }
    
    void tranverse(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL || t2 == NULL){
            return;
        }
        
        //overlap
        t1->val += t2->val;
        
        if(t1->left == NULL && t2->left != NULL){ //copy to left
            t1->left = t2->left;
            t2->left = NULL;
        }
        tranverse(t1->left, t2->left);
        
        if(t1->right == NULL && t2->right != NULL){ //copy to right
            t1->right = t2->right;
            t2->right = NULL;
        }
        tranverse(t1->right, t2->right);
    }
};