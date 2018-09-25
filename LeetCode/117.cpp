/*
  117
  Populating Next Right Pointers in Each Node II
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
        while (node && (node->left || node->right)) { // every level
            cur = node;

            while (cur) { // every node in the level
                TreeLinkNode *tmp = cur;

                if (cur->left && cur->right) {
                    cur->left->next = cur->right; // left
                    move(cur, cur->right); // right
                }
                else if (cur->left) { // left
                    move(cur, cur->left);
                }
                else if (cur->right) { // right
                    move(cur, cur->right);
                }
                
                if (cur == tmp) { // if not moved, move next
                    cur = cur->next;
                }
            }
            
            // find next start node in the next level
            while (node) {
                if (node->left && (node->left->left || node->left->right)) {
                    node = node->left;
                    break;
                }
                else if (node->right && (node->right->left || node->right->right)) {
                    node = node->right;
                    break;
                }
                
                node = node->next;
            }
        }
    }
    
    // find next node in the same level
    void move(TreeLinkNode *&cur, TreeLinkNode *&p){
        while (cur->next) {
            if (cur->next->left) {
                p->next = cur->next->left;
                break;
            } else if (cur->next->right) {
                p->next = cur->next->right;
                break;
            }

            cur = cur->next; 
        } 
    }
};