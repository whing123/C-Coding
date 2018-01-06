/* *题目：
 *  二叉树的序列化
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
};*/
 
class TreeToSequence {
public:
    string toSequence(TreeNode* root) {
        string res;
        if(root == NULL){
            return res;
        }
         
        res += "(";
        res += toSequence(root->left);
        res += toSequence(root->right);
        res += ")";
        return res;
    }
};