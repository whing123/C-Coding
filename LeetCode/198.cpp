/* *题目：
 *  671
 *  Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        
        vector<int> leafs;
        leafNodes(root, leafs);
        
        int min_val = root->val; // minimum
        sort(leafs.begin(), leafs.end());
        
        for(int i = 1; i < leafs.size(); ++i){
            if(leafs[i] > min_val){ // if exists
                return leafs[i];
            }
        }
        
        return -1;
    }
    
    // find all leaf nodes, note that no sinle subnode
    void leafNodes(TreeNode* root, vector<int>& nodes){
        if(root->left == NULL && root->right == NULL){ // leaf node
            nodes.push_back(root->val);
            return;
        }
        
        leafNodes(root->left, nodes);
        leafNodes(root->right, nodes);
    }
    
}; 