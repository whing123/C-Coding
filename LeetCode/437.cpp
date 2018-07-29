/* *题目：
 *  437
 *  Path Sum III
 * *思路：

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
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        vector<int> path; // 从根开始路径中各节点到末端节点的累加和
        preScan(root,sum,cnt,path);
        return cnt;
    }
    
    void preScan(TreeNode* root, int sum, int& cnt, vector<int>& path){
        if(root == NULL){
            return;
        }
        cnt += pathCount(path,sum,root->val);
        preScan(root->left,sum,cnt,path);
        preScan(root->right,sum,cnt,path);
        update(path);
    }
    
    int pathCount(vector<int>& path, int sum, int val){
        int cnt = 0;
        for(int i = 0;i < path.size();i++){
            path[i] += val;
            if(path[i] == sum){
                cnt++;
            }
        }
        path.push_back(val);
        if(val == sum){
            cnt++;
        }
        return cnt;
    }
    
    void update(vector<int>& path){
        int tmp = path[path.size()-1];
        path.erase(path.end()-1);
        for(int i = 0;i < path.size();i++){
            path[i] -= tmp;
        }
    }
    
};

// better
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        vector<int> path;
        dfs(root, sum, cnt, path);
        
        return cnt;
    }
    
    void dfs(TreeNode* root, int sum, int& cnt, vector<int>& path){
        if(root == NULL){
            return;
        }
        
        // pre process
        for(int i = 0; i < path.size(); i++){
            path[i] += root->val;
            if(path[i] == sum){
                cnt++;
            }
        }
        path.push_back(root->val);
        if(root->val == sum){
            cnt++;
        }
        
        dfs(root->left, sum, cnt, path);
        dfs(root->right, sum, cnt, path);
        
        // post process
        path.pop_back();
        for(int i = 0; i < path.size(); i++){
            path[i] -= root->val;
        }
    }  
};