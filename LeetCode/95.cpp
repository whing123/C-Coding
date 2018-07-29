/*
  95
  Unique Binary Search Trees II
*/

/*
当前的递归中，假设root为i，那么左子树是由[1,i-1]构成的所有可能的组合，右子树是由[i+1,n]构成的所有可能的组合
可以用[start, end]去构建树
在有了左子树，root，右子树的情况下，根据乘法原理很容易计算得出在当前情况下所有的树

if we take i as root, (1 <= i <= n), obviously, (1 .. i-1) will be the left subtree, (i+1 .. n) will be the right subtree, 
we can also process the left subtree and the right sub tree in the way above...
Great, we have found the overlapped subproblem.
We define state : dp[s][e], all structurally unique BSTs that stores [s .. e], then our aim state is : dp[1][n].
if we take i as root, (s <= i <= e),
all structurally unique BSTs as its left subtree, dp[1][i-1],
all structurally unique BSTs as its right subtree,dp[i+1][n],
all possible combinations of them will be the final answer.
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        return generateTrees_helper(1, n);
    }
    
    vector<TreeNode*> generateTrees_helper(int st, int ed){
        vector<TreeNode*> res;
        if(st > ed){
            res.push_back(NULL);
            return res;
        }
        
        for(int i = st; i <= ed; i++){ // choose i as the root
            vector<TreeNode*> ltree = generateTrees_helper(st, i-1); // all kinds of left trees
            vector<TreeNode*> rtree = generateTrees_helper(i+1, ed); // all kinds of right trees
            for(int j = 0; j < ltree.size(); j++){
                for(int k = 0; k < rtree.size(); k++){
                    TreeNode* root = new TreeNode(i); // root
                    root->left = ltree[j]; // choose its left tree
                    root->right = rtree[k]; // choose its right tree
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};