/* *题目：
 *  653
 *  Two Sum IV - Input is a BST
 * *思路：
return true if there exist two elements in the BST 
such that their sum is equal to the given target
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> table;
        return search(root, table, k);
    }
    
    bool search(TreeNode* root, unordered_set<int>& sets, int k){
        if(root == NULL){
            return false;
        }
        
        if(sets.count(k - root->val)){  // check if k-a exists
            return true;
        }
        
        sets.insert(root->val);
        
        return search(root->left, sets, k) || search(root->right, sets, k);
    }
};

// another
bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    for(int i = 0, j = nums.size()-1; i<j;){
        if(nums[i] + nums[j] == k)return true;
        (nums[i] + nums[j] < k)? i++ : j--;
    }
    return false;
}


// another
void inorder(TreeNode* root, vector<int>& nums){
    if(root == NULL)return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

bool findTarget(TreeNode* root, int k) {
    return dfs(root, root,  k);
}

bool dfs(TreeNode* root,  TreeNode* cur, int k){
    if(cur == NULL)return false;
    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

bool search(TreeNode* root, TreeNode *cur, int value){
    if(root == NULL)return false;
    return (root->val == value) && (root != cur) 
        || (root->val < value) && search(root->right, cur, value) 
            || (root->val > value) && search(root->left, cur, value);
}