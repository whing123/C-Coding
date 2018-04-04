/* *题目：
 *  235
 *  Lowest Common Ancestor of a Binary Search Tree
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


// better
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){ // 找到其中一个就返回
            return root;
        }

        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if(L && R){ // 如果在root的左右子树分别找到，则返回root
            return root;
        }
        
        return L ? L : R; // 如果只找到其中一个，说明在root同一个子树上，那么该节点就是公共祖先
    }
};

// recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;
    }
};

// iterative
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};