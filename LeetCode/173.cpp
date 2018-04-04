/* *题目：
 *  173
 *  Binary Search Tree Iterator
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = st.top();
        st.pop();
        
        if(p->right != NULL){
            find_left(p->right);
        }
        
        return p->val;
    }
    
    void find_left(TreeNode *root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    
private:
    stack<TreeNode *> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */