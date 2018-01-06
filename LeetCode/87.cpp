/* *题目：
 *  257
 *  Binary Tree Paths
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