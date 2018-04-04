/* *题目：
 *  二叉搜索树的下几个节点
 */

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node() :val(0), left(NULL), right(NULL) {}
	Node(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	Node* findNext(int m, stack<Node*> &s, Node* p)
	{
		if (p == NULL || m == 0) {
			return p;
		}

		if (p->right) {
			s.push(p);
			p = p->right;
			while (p->left) {
				s.push(p);
				p = p->left;
			}
			
			return findNext(m - 1, s, p);
		}

		while (!s.empty()) {
			if (p == s.top()->left) {
				Node* tmp = s.top();
				s.pop();

				return findNext(m - 1, s, tmp);
			}

			p = s.top();
			s.pop();
		}

		return NULL;
	}

	Node* search(Node* root, Node* X)
	{
		if(root == NULL || X == NULL){
			return NULL;
		}

		// step 1: find the X, and record its fathers in a stack
		Node *tmp = root;
		stack<Node*> s;
		while (tmp != NULL && tmp != X)
		{
			s.push(tmp);
			if (tmp->val > X->val)
			{
				tmp = tmp->left;
			}
			else if (tmp->val < X->val)
			{
				tmp = tmp->right;
			}
		}
		if(tmp == NULL){ // not found
			return NULL;
		}

		// step 2: find the next of the next of X
		return findNext(2, s, tmp);
	}
};
