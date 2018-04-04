/* *题目：
 *  102
 *  Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        queue<TreeNode*> curLevel, nextLevel;
        TreeNode* curr;
        curLevel.push(root);
        while(!curLevel.empty()){
            vector<int> tmp;

            while(!curLevel.empty()){
                curr = curLevel.front();
                curLevel.pop();
                tmp.push_back(curr->val);

                if(curr->left){
                    nextLevel.push(curr->left);
                }
                if(curr->right){
                    nextLevel.push(curr->right);
                }
            }
            
            result.push_back(tmp);
            while(!nextLevel.empty()){
                curLevel.push(nextLevel.front());
                nextLevel.pop();
            }
        }
        return result;
    }
};