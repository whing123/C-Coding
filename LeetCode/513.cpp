/* *题目：
 *  513
 *  Find Bottom Left Tree Value 
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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int res;
        if(getHeight(root->left) >= getHeight(root->right)){ //左子树高于右子树时去找左边，左边优先级高
            res = findBottomLeftValue(root->left);           //左右一样高找左边，否则找最高的
        }else{
            res = findBottomLeftValue(root->right);
        }
        return res;
    }
    
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        
        return 1 + (leftH > rightH ? leftH : rightH);
    }
};

// better
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        helper(root, 1, res);
        return res.back();
    }
    
    void helper(TreeNode* root, int level, vector<int> & vec){
        if(root == NULL){
            return;
        }
        
        if(vec.size() < level) vec.push_back(root->val); // 一层一个，每一层最左侧先遍历到
        helper(root->left, level+1, vec);
        helper(root->right, level+1, vec);
    }
};