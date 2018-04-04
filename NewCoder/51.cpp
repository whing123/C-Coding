/* *题目：
 *  中序遍历下个节点
 * *思路：
 *  
 */

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

/*
 1、有右子树的，那么下个结点就是右子树最左边的点；
 2、没有右子树的，也可以分成两类：
 a)是父节点左孩子，那么父节点就是下一个节点；
 b)是父节点的右孩子，则找他的父节点的父节点，重复2...直到当前节点是其父节点的左孩子
*/


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL){
            return NULL;
        }
        
        // 右子树不空，找右子树最左侧节点
        if(pNode->right != NULL){
            pNode = pNode->right;
            while(pNode->left != NULL){
                pNode = pNode->left;
            }
            
            return pNode;
        }
        
        // 右子树不存在，只能往上走
        while(pNode->next != NULL){
            if(pNode == pNode->next->left){ // 若其是父节点的左子树，下一个即是父节点
                return pNode->next;
            }
            pNode = pNode->next; // 否则，继续往上走
        }
        
        return NULL;
    }
};