/* *题目：
 *  103
 *  Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> d;
        d.push(root);
        bool dir = false;
        
        while(!d.empty()){
            vector<int> vec;
            int size = d.size();
            
            while(size--){
                TreeNode* p = d.front();
                d.pop();
                vec.push_back(p->val);
                
                if(p->left != NULL){
                    d.push(p->left);
                }
                if(p->right != NULL){
                    d.push(p->right);
                }
            }
            
            if(dir){ // to reverse
                reverse(vec.begin(), vec.end());
            }
            dir = !dir;
            
            res.push_back(vec);
        }
        
        return res;
    }
};