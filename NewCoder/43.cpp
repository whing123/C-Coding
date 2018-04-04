/* *题目：
 *  层序遍历
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == NULL){
            return res;
        }
        
        queue<TreeNode*> tmp;
        tmp.push(pRoot);
        while(!tmp.empty()){
            
            vector<int> vec;
            
            int size = tmp.size();
            while(size--){
                TreeNode* p = tmp.front();
                vec.push_back(p->val);
                tmp.pop();
                if(p->left != NULL){
                    tmp.push(p->left);
                }
                if(p->right != NULL){
                    tmp.push(p->right);
                }
            }
            res.push_back(vec);
        }
        
        return res;
    }
};