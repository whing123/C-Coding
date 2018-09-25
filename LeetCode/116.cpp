/* *题目：
 *  116
 *  Populating Next Right Pointers in Each Node
 * *思路：
 *  
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeLinkNode *node = root;
        TreeLinkNode *cur = NULL;
        while (node->left) { // every level
            cur = node;
            while (cur) { // every node in the level
                cur->left->next = cur->right; // its left
                if (cur->next) { // its right
                    cur->right->next = cur->next->left;
                }
                
                cur = cur->next; 
            }
            
            node = node->left;
        }
    }
};