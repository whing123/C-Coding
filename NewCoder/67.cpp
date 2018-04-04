/* *题目：
 *  二叉搜索树与双向链表
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL){
            return NULL;
        }
        TreeNode* pre = NULL; // 当前节点的前一节点
        Convert(pRootOfTree, pre);
            
        TreeNode* res = pRootOfTree;
        while(res->left){ // 找到头
            res = res->left;
        }

        return res;
    }
    
    // 中序遍历
    void Convert(TreeNode* root, TreeNode*& pre){
        if(root == NULL){
            return;
        }
        
        Convert(root->left, pre);
        root->left = pre;
        if(pre) pre->right = root;
        pre = root;
        Convert(root->right, pre);
    }
};

// 非递归版
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {

        TreeNode *head = NULL, *pre = NULL; // head 输出，pre记录上一次出栈值
        stack<TreeNode*> s;
        while (pRootOfTree || !s.empty())
        {
            while (pRootOfTree)
            {
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            if (!s.empty())
            {
                pRootOfTree = s.top();
                s.pop();
                if (pre != NULL)
                {
                    pre->right = pRootOfTree;
                    pRootOfTree->left = pre;
                }
                else // pre为空，表示s第一次出栈，第一次出栈值为最左值，即输出值
                {
                    head = pRootOfTree;
                }
                
                pre = pRootOfTree;
                pRootOfTree = pRootOfTree->right;
            }
        }
        
        return head;
    }
    
};