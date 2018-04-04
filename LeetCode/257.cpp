/* *题目：
 *  257
 *  Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<string> seq; // 1, 1->2, 1->2->5, 1->3
        vector<string> path; // ["1->2->5", "1->3"]
        searchPaths(root,path,seq);
        return path;
    }
    void searchPaths(TreeNode* root, vector<string>& path, stack<string>& seq){
        if(root == NULL){
            return;
        }
        string node;
        if(seq.empty()){
            node = to_string(root->val);
            seq.push(node);
        }else{
            node = seq.top() + "->" + to_string(root->val);
            seq.push(node);
        }
        if(root->left == NULL && root->right == NULL){  // leaf node
            path.push_back(seq.top());
            seq.pop();
            return;
        }
        searchPaths(root->left,path,seq);
        searchPaths(root->right,path,seq);
        seq.pop();
    }
};


// better
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL){
            return res;
        }
        
        string str(to_string(root->val));
        dfs(root, res, str, 1);
        return res;
    }
    
    void dfs(TreeNode* root, vector<string>& res, string cur, int level){
        if(root == NULL){
            return;
        }
        
        string now;
        if(level > 1){
            now = "->" + to_string(root->val);
        }else{
            now = "";
        }
        
        if(root->left == NULL && root->right == NULL){
            res.push_back(cur + now);
            return;
        }
        
        dfs(root->left, res, cur+now, level+1);
        dfs(root->right, res, cur+now, level+1);
    }
};