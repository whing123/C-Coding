/* *题目：
 *  297
 *  Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(root == NULL)
            return res;
        
        sHelper(root, res);
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return NULL;
        }
        
        string str(data);
        return dHelper(str);
    }
    
    void sHelper(TreeNode *root, string& s){
        if(root == NULL){
            s += "N,";
            return;
        }
        
        s += to_string(root->val);
        s += ",";
        sHelper(root->left, s);
        sHelper(root->right, s);
    }
    
    TreeNode* dHelper(string& s){
        if(s.empty()){
            return NULL;
        }
        
        if(s[0] == 'N'){
            s = s.substr(2);
            return NULL;
        }
        
        int index = s.find_first_of(',');
        TreeNode* res = new TreeNode(stoi(s.substr(0, index)));
        s = s.substr(index+1);
        res->left = dHelper(s);
        res->right = dHelper(s);
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
