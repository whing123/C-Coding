/* *题目：
 *  拓扑结构相同子树
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
 
class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        if(A == NULL && B != NULL){ // 这句不能掉，否则可能会抛出空指针异常
            return false;
        }
         
        if(isSame(A, B) || chkIdentical(A->left, B) || chkIdentical(A->right, B)){
            return true;
        }
         
        return false;
    }
     
    bool isSame(TreeNode* A, TreeNode* B){
        if(A == NULL && B == NULL){
            return true;
        }
         
        if(A == NULL || B == NULL){
            return false;
        }
         
        return A->val == B->val && isSame(A->left, B->left) && isSame(A->right, B->right);
    }
};


/*
1、添加缺失的叶子节点，将树转换成满树，这样才能完整地表达树的结构
2、将树转换成字符串，用字符串中查找字串来完成（string的find）
*/

void preOrder(TreeNode* t, string &s)
{
  if(t != NULL)
    {
        s += ('0' + t->val);
        preOrder(t->left, s);
        preOrder(t->right, s);
    }
    else
    {
        s += '#'; // 缺失的叶子节点
    }
}
 
bool chkIdentical(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL) return true;
    if(A && B)
    {
        string sA, sB;
        preOrder(A, sA);
        preOrder(B, sB);
        if(sA.find(sB) != string::npos) return true;
    }
     
    return false;
}