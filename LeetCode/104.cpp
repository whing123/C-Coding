/* *题目：
 *  104
 *  Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftD = maxDepth(root->left), rightD = maxDepth(root->right);
        return 1 +  (leftD > rightD ? leftD : rightD);
    }
};