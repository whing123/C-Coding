/* *题目：
 *  序列化二叉树
 * *思路：
 *  
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(root == NULL)
            return NULL;
        string res = "";
        sHelper(root, res);
        
        char *s = new char[res.length()+1];
        strcpy(s, res.c_str());
        return s;
    }
    TreeNode* Deserialize(char *str) {
        if(str == NULL){
            return NULL;
        }
        string s(str);
        return dHelper(s);
    }
private:
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