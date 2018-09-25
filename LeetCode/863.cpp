/* *题目：
 *  863
 *  All Nodes Distance K in Binary Tree
 * *思路：

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        
        vector<TreeNode*> path;
        findTarget(root, target, path); // 找到这条到target的路径
        
        set<TreeNode*> hashSet; // 做成集合
        for (int i = 0; i < path.size(); i++) {
            hashSet.insert(path[i]);
        }
        
        // 遍历这条路径
        for (int i = 0; i < path.size(); i++) {
            if (K < path.size()-1-i) {
                continue;
            }
            else if (K == path.size()-1-i) {
                res.push_back(path[i]->val);
            } else {
                set<TreeNode*> newSet = hashSet;
                newSet.erase(path[i]); // 新集合要去掉当前根节点
                findDistK(path[i], newSet, K-(path.size()-1-i), res);
            }
        }
        
        return res;
    }
    
    bool findTarget(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root != NULL) {
            path.push_back(root);
            
            if (root == target) { // 找到目标
                return true;
            }
            
            if (findTarget(root->left, target, path) || findTarget(root->right, target, path)) {
                return true;
            }
            
            path.pop_back();
        }
        
        return false;
    }
    
    void findDistK(TreeNode* root, set<TreeNode*>& hashSet, int K, vector<int>& res) {
        if (root != NULL) {
            if (hashSet.find(root) != hashSet.end()) { // 当前查找的路径节点若出现过，则返回
                return;
            }
            
            if (K-- == 0) {
                res.push_back(root->val);
                return;
            }
            
            findDistK(root->left, hashSet, K, res);
            findDistK(root->right, hashSet, K, res);
        }
    }
};