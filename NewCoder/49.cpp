/* *题目：
 *  二叉树中和为某一值的路径
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
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> path; // 从根到末端节点路径
        int path_sum = 0; // 从根到末端节点的累加和
        preScan(root,expectNumber,path_sum,res,path);
        return res;
    }
     
    void preScan(TreeNode* root, int sum, int& path_sum, vector<vector<int>>& res, vector<int> &path){
        if(root == NULL){
            return ;
        }
         
        if(root->left == NULL && root->right == NULL){
            if(path_sum + root->val == sum){
                path.push_back(root->val);
                vector<int> new_path(path.begin(),path.end());
                res.push_back(new_path);
                 
                path.erase(path.end()-1);
            }
            return;
        }
         
        path_sum += root->val;
        path.push_back(root->val);
        preScan(root->left,sum,path_sum,res,path);
        preScan(root->right,sum,path_sum,res,path);
        path_sum -= root->val;
        path.erase(path.end()-1);
    }
};

// 改进

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> path; // 从根到末端节点路径
        int path_sum = 0; // 从根到末端节点的累加和
        preScan(root,expectNumber,path_sum,res,path);
        return res;
    }
     
    void preScan(TreeNode* root, int sum, int& path_sum, vector<vector<int>>& res, vector<int> &path){
        if(root == NULL){
            return;
        }
         
        path.push_back(root->val);
        path_sum += root->val;
         
        if(root->left == NULL && root->right == NULL){
            if(path_sum == sum){
                res.push_back(path);
            }
        }
         
        preScan(root->left,sum,path_sum,res,path);
        preScan(root->right,sum,path_sum,res,path);
         
        path_sum -= root->val;
        path.pop_back();
    }
};

