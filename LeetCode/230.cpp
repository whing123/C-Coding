/* *题目：
 *  662
 *  Maximum Width of Binary Tree
 * *思路：
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int maxL = 0;
        
        queue<pair<TreeNode*,int>> tmp;
        tmp.push(pair<TreeNode*,int>(root,1)); // id from 1
        while(!tmp.empty()){
            int l = tmp.front().second, r = l;
            for(int i = 0, n = tmp.size(); i < n; ++i){
                TreeNode* p = tmp.front().first; 
                r = tmp.front().second;
                tmp.pop();

                if(p->left){
                    tmp.push(pair<TreeNode*,int>(p->left, 2 * r));
                }
                if(p->right){
                    tmp.push(pair<TreeNode*,int>(p->right, 2 * r + 1));
                }
            }
            
            if(maxL < r - l + 1){
                maxL = r-l+1;
            }

        }
        
        return maxL;  
    }
};