/* *题目：
 *  按之字形顺序打印二叉树
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
         
        deque<TreeNode*> data;
        data.push_front(pRoot);
         
        bool dir = true; // 从左到右
        while(!data.empty()){
            vector<int> vec;
            int size = data.size();
 
            while(size--){
                TreeNode* tmp = dir ? data.front() : data.back();
                vec.push_back(tmp->val);
                if(dir){
                    data.pop_front();
                }else{
                    data.pop_back();
                }
                 
                if(dir){
                    if(tmp->left)
                        data.push_back(tmp->left);
                    if(tmp->right)
                        data.push_back(tmp->right);
                }else{
                    if(tmp->right)
                        data.push_front(tmp->right);
                    if(tmp->left)
                        data.push_front(tmp->left);
                }
            }
             
            res.push_back(vec);
            dir = !dir;
        }
         
        return res;
    }
     
};

// better
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL)
            return res;
        
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;

        while(!que.empty()){
            vector<int> vec;
            int size = que.size();
            while(size--){
                TreeNode* tmp = que.front();
                que.pop();
                vec.push_back(tmp->val);
                
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
            if(even) // 方向判断
                std::reverse(vec.begin(), vec.end());
            even = !even;
            res.push_back(vec);
        }
        return res;
    }
    
};