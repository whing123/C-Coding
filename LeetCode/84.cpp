/* *题目：
 *  235
 *  Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p && root == q){
            return root;
        }
        else if(root == p){
            if(isExisted(root->left,q) || isExisted(root->right,q)){
                return root;
            }
        }else if(root == q){
            if(isExisted(root->left,p) || isExisted(root->right,p)){
                return root;
            }
        }else if(isExisted(root->left,p) && isExisted(root->right,q) || isExisted(root->left,q) && isExisted(root->right,p)){
            return root;
        }
        TreeNode* tmp;
        tmp = lowestCommonAncestor(root->left,p,q);
        if(tmp){
            return tmp;
        }
        tmp =lowestCommonAncestor(root->right,p,q);
        if(tmp){
            return tmp;
        }
        return NULL;
    }
    
    bool isExisted(TreeNode* root, TreeNode* p){
        if(root == NULL){
            return false;
        }
        return root == p || isExisted(root->left, p) || isExisted(root->right, p);
    }
};

