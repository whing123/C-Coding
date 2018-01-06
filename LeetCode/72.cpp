/* *题目：
 *  107
 *  Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> curlevel, nextlevel;
        curlevel.push(root);
        while(!curlevel.empty()){
            vector<int> tmp;
            while(!curlevel.empty()){
                TreeNode* cur = curlevel.front();
                curlevel.pop();
                tmp.push_back(cur->val);
                if(cur->left){
                    nextlevel.push(cur->left);
                }
                if(cur->right){
                    nextlevel.push(cur->right);
                }
            }
            result.insert(result.begin(),tmp);
            while(!nextlevel.empty()){
                curlevel.push(nextlevel.front());
                nextlevel.pop();
            }
        }
        return result;
    }
};