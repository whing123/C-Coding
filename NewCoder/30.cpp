/* *题目：
 *  输出单层结点
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
 
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {      
        if(root == NULL)
            return NULL;
         
        ListNode *head, *cur;
         
        queue<TreeNode*> levels;
        levels.push(root);
         
        int cnt = 1;
        while(!levels.empty()){
            dep--; // 层数变化
             
            int count = 0;
            for(int i = 0; i < cnt; ++i){ // 当前层的所有结点
                TreeNode* tmp = levels.front();
                levels.pop();
                 
                if(dep > 0){
                    if(tmp->left != NULL){
                        levels.push(tmp->left);
                        count++;
                    }
                    if(tmp->right != NULL){
                        levels.push(tmp->right);
                        count++;
                    }
                }else{  // 到达指定层
                    if(i == 0){ // 头结点
                        cur = head = new ListNode(tmp->val);
                    }else{
                        cur->next = new ListNode(tmp->val);
                        cur = cur->next;
                    }
                }  
            }
             
            cnt = count; // 下层结点数
        }
         
        return head;
    }
};

/*
    其实也可以用递归遍历实现，刚开始为深度为dep，每往下递归一层，则深度减一（dep=dep-1），
    当dep==1的时候，便输出那个元素，如果先递归左子树，那么则实现从左到右打印，如果先递归右子树，则实现从右往左打印。
*/

class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        ListNode* head  = new ListNode(-1);
        ListNode* list = head;

        get(root, list, dep);

        return head->next;
    }

    void get(TreeNode* root, ListNode* &list, int dep)
    {
        if(dep <= 0 || root == NULL)
            return;
        if(dep == 1)
        {
            list->next = new ListNode(root->val);
            list = list->next;
            return;
        }
        get(root->left, list, dep-1);
        get(root->right, list, dep-1);
    }
};