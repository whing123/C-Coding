/* *题目：
 *  654
 *  Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        
        TreeNode *root;
        makeTree(root, nums, 0, nums.size()-1);
        
        return root;
    }
    
    void makeTree(TreeNode* &root, vector<int>& nums, int left, int right){
        if(left > right){
            return;
        }
        
        int index = findMaxIndex(nums, left, right);
        root = new TreeNode(nums[index]);
        makeTree(root->left, nums, left, index-1); // left
        makeTree(root->right, nums, index+1, right); // right
    }
    
    // find the index of Max
    int findMaxIndex(vector<int>& nums, int left, int right){
        int index = 0;
        int tmp = INT_MIN;
        for(int i = left; i <= right; ++i){
            if(nums[i] > tmp){
                tmp = nums[i];
                index = i;
            }
        }
        
        return index;
    }
    
};