/* *题目：
 *  108
 *  Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }else if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        
        int mid = nums.size()/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        vector<int> left = vector<int>(nums.begin(), nums.begin()+mid);
        vector<int> right = vector<int>(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
                                      
        return root;
    }
};