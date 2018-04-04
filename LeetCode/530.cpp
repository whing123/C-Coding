/* *题目：
 *  530
 *  Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        searchAllNodes(root,res); //前序遍历
        sort(res.begin(),res.end()); //排序
        
        int value = INT_MAX;
        for(int i = 0; i < res.size()-1;i++){
            if(abs(res[i]-res[i+1]) < value){  //寻找最小差异
                value = abs(res[i]-res[i+1]);
            }
        }
        return value;
    }
    
    void searchAllNodes(TreeNode* root, vector<int> &table){ 
        if(root == NULL){
            return;
        }
        table.push_back(root->val);
        searchAllNodes(root->left,table);
        searchAllNodes(root->right,table);
    }
};