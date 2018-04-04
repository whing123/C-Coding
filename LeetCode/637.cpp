/* *题目：
 *  637
 *  Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> levels;
        levels.push(root);
        
        int cnt = 1;
        while(!levels.empty()){
            int count = 0;
            double sum = 0;

            for(int i = 0; i < cnt; ++i){
                TreeNode* tmp = levels.front();
                levels.pop();
                
                sum += tmp->val;
                
                if(tmp->left != NULL){
                    levels.push(tmp->left);
                    count++;
                }
                if(tmp->right != NULL){
                    levels.push(tmp->right);
                    count++;
                }
            }
            
            res.push_back(sum / cnt);
            
            cnt = count;
            
        }
        
        return res;
        
    }
};



