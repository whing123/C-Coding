/* *题目：
 *  671
 *  Second Minimum Node In a Binary Tree
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

/*
This question is very similar to searching for minimum value in the Binary Tree.
The only requirement is that this value must be different from the root value, k.

If the root value of a subtree == k, 
         keep searching its children.
else, 
         return the root value because it is the minimum of current subtree.
*/
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int ans = minval(root, root->val);
        return ans;
    }
    
private:
    int minval(TreeNode* p, int first) {
        if (p == nullptr) return -1;
        if (p->val != first) return p->val;
        
        // p->val == first
        int left = minval(p->left, first), right = minval(p->right, first);
        // if all nodes of a subtree = root->val,
        // there is no second minimum value, return -1
        
        if (left == -1) return right;
        if (right == -1) return left;
        
        // find min, if exist in both sub trees
        return min(left, right);
    }
}; 