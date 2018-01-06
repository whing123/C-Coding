/* *题目：
 *  508
 *  Most Frequent Subtree Sum
 * *思路：
 *  
 * *技法：
 *  
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
 
 
//比较器 vector<pair<int,int>>
struct Greater {
	bool operator()(const pair<int,int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
		//保存和，及其频率
		map<int, int> sums;
		findSums(root, sums);

		//map改成vector，进行排序
		vector<pair<int, int>> tmp(sums.begin(), sums.end());
		//按频次排序，由大到小
		sort(tmp.begin(), tmp.end(), Greater());

		int v = tmp[0].second;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i].second == v) {  //寻找频次最高的
				res.push_back(tmp[i].first);
			}else {
				break;
			}
		}

		return res;
	}

	void findSums(TreeNode* root, map<int, int> &sums) {

		//到达根部，存储其值
		if (root->left == NULL && root->right == NULL) {
			//cout << root->val<<' ';
			sums[root->val]++;
			return;
		}

		int sum = 0;
		if (root->left) {
			findSums(root->left,sums);
			sum += root->left->val;  //加上左子树的值
		}
		if (root->right) {
			findSums(root->right,sums);
			sum += root->right->val;  //加上右子树的值
		}
		root->val += sum;  //再加上自身
		//cout << root->val << ' ';
		sums[root->val]++;  

	}
};