/* *题目：
 *  前序中序重建二叉树
 * *思路：
 *  
 */

 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0){
            return NULL;
        }
        
        // 当前子树根节点
        TreeNode* root = new TreeNode(pre[0]); 
        int index; // find中序下标
        for(int i = 0; i < vin.size(); ++i){
            if(vin[i] == pre[0]){
                index = i;
                break;
            }
        }
        
        // 左子树
        vector<int> l_pre(pre.begin()+1, pre.begin()+1+index);
        vector<int> l_vin(vin.begin(), vin.begin()+index);
        root->left = reConstructBinaryTree(l_pre, l_vin);
        
        // 右子树
        vector<int> r_pre(pre.begin()+1+index, pre.end());
        vector<int> r_vin(vin.begin()+index+1, vin.end());
        root->right = reConstructBinaryTree(r_pre, r_vin);
        
        return root;
    }
};