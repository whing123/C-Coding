/* *题目：
 *  101
 *  Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        vector<int> leftTree, rightTree;
        getLeft(root->left,leftTree);
        getRight(root->right,rightTree);
        if(leftTree.size() != rightTree.size()){
            return false;
        }
        for(int i = 0;i < leftTree.size();i++){
            if(leftTree[i] != rightTree[i]){
                return false;
            }
        }
        return true;
    }
    
    void getLeft(TreeNode* root, vector<int>& tmp){
        if(root == NULL){
            tmp.push_back(0);
            return;
        }
        tmp.push_back(root->val);
        getLeft(root->left,tmp);
        //tmp.push_back(root->val);
        getLeft(root->right,tmp);
    }
    
    void getRight(TreeNode* root, vector<int>& tmp){
        if(root == NULL){
            tmp.push_back(0);
            return;
        }
        tmp.push_back(root->val);
        getRight(root->right,tmp);
        //tmp.push_back(root->val);
        getRight(root->left,tmp);
    }
};

// better
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return isSys(root->left, root->right);
    }
    
    bool isSys(TreeNode* ltree, TreeNode* rtree){
        if(ltree == NULL && rtree == NULL){
            return true;
        }else if(ltree == NULL || rtree == NULL){
            return false;
        }
        
        return ltree->val == rtree->val && isSys(ltree->left, rtree->right) && isSys(ltree->right, rtree->left);
    }
};