/* *题目：
 *  515
 *  Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> tree;
        queue<TreeNode*> row;
        
        TreeNode* tmp;
        
        tree.push(root);
        while(!tree.empty()){
            while(!tree.empty()){   // 存入行队列中
                row.push(tree.front());
                tree.pop();
            }
            
            int value = INT_MIN;
            while(!row.empty()){  // 对当前行，寻找最大值，并将子结点送入tree队列，保证当前层和下一层分离
                tmp = row.front();
                row.pop();
                if(tmp->val > value){
                    value = tmp->val;
                }
                
                if(tmp->left){
                    tree.push(tmp->left);
                }
                if(tmp->right){
                    tree.push(tmp->right);
                }
            }
            
            res.push_back(value);
        }
        
        return res;
    }
};

// better
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> row;
        
        row.push(root);
        while(!row.empty()){
            int value = INT_MIN;
            
            int size = row.size();
            while(size--){  // 对当前行，寻找最大值，并将子结点送入row队列，保证当前层和下一层分离
                TreeNode* tmp = row.front();
                row.pop();
                if(tmp->val > value){
                    value = tmp->val;
                }
                
                if(tmp->left){
                    row.push(tmp->left);
                }
                if(tmp->right){
                    row.push(tmp->right);
                }
            }
            
            res.push_back(value);
        }
        
        return res;
    }
};

// better
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        dfs(root, res, 1);
            
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res, int level){
        if(root == NULL){
            return;
        }
        
        if(res.size() < level){ // first coming
            res.push_back(root->val);
        }else{ // ever reached this level
            if(root->val > res[level-1]){
                res[level-1] = root->val;
            }
        }
        
        dfs(root->left, res, level+1);
        dfs(root->right, res, level+1);
    }
};