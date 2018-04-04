/* *题目：
 *  114
 *  Flatten Binary Tree to Linked List
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

// each node's right child points to the next node of a pre-order traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        pre(root, prev);
    }
    
    void pre(TreeNode* root, TreeNode*& prev){
        if(root != NULL){
            pre(root->right, prev); // right
            pre(root->left, prev); // left
            
            // root
            root->right = prev;
            root->left = NULL;
            
            prev =  root;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
            root = root->right;
        root->right = tmp;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode* t = root->left;
                while (t->right)
                    t = t->right;
                t->right = root->right;
            }

            if(root->left)
                root->right = root->left;
            root->left = NULL;
            
            root = root->right;
        }
    }
};