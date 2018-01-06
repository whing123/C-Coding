/* *题目：
 *  501
 *  Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        map<int, int> table; // val->count
        int maxCnt = 0; // max count
        
        preOrder(root, table, maxCnt);
        
        vector<int> res;
        map<int, int>::iterator it;
        for(it = table.begin(); it != table.end(); it++){
            if(it->second == maxCnt){ // if find modes
                res.push_back(it->first);
            }
        }
        return res;
    }
    
    void preOrder(TreeNode* root, map<int, int>& tab, int& maxCnt){
        if(root == NULL){
            return;
        }
        
        if(tab.find(root->val) == tab.end()){ // if not existed, to search it
            int cnt = 0;
            findCount(root, root->val, cnt); // find its count
            tab[root->val] = cnt; // record this map, val->count
            
            if(cnt > maxCnt){ // update max count
                maxCnt = cnt;
            }
        }
        
        preOrder(root->left, tab, maxCnt);
        preOrder(root->right, tab, maxCnt); 
    }
    
    void findCount(TreeNode* root, int val, int& cnt){
        if(root == NULL){
            return;
        }
        
        if(root->val == val) // if matched
            cnt++;
        
        findCount(root->left, val, cnt);
        findCount(root->right, val, cnt);
    }
};