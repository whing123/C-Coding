/* *题目：
 *  145
 *  Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        postorder(root, res);
        
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& vec){
        if(root == NULL){
            return;
        }
        
        postorder(root->left, vec);
        postorder(root->right, vec);
        
        vec.push_back(root->val);
    }
};

class Solution {
    struct Count {
        TreeNode *node;
        int cnt;
        Count(TreeNode *n): node(n), cnt(0) {}  
    };
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        stack<Count> st;
        st.push(Count(root));
        
        while(!st.empty()){
            Count p = st.top();
            st.pop();
            if(++p.cnt == 3){
                res.push_back(p.node->val);
                continue;
            }
            
            st.push(p);
            
            if(p.cnt == 1){
                if(p.node->left != NULL){
                   st.push(Count(p.node->left)); 
                }
            }
            
            if(p.cnt == 2){
                if(p.node->right != NULL){
                   st.push(Count(p.node->right)); 
                }
            }
            
        }
        
        return res;
    }
};