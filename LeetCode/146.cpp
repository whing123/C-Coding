/* *题目：
 *  406
 *  Queue Reconstruction by Height
 * *思路：
 *  
 * *技法：
 *  
 */

struct LessSecond
{
	bool operator()(const pair<int, int> &x, const pair<int, int> &y) const
	{
		return x.first > y.first || (x.first == y.first && x.second < y.second);
	}
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),LessSecond()); //按第一个数从大到小排序，相等时第二个数从小到大排序，构成了插入的优先级
        vector<pair<int, int>> result;
        
        int  i;
        vector<pair<int, int>>::iterator it;
        for(auto p : people){
            it = result.begin();
            i = 0;
            while(/*it != result.end() && */i < p.second){ 
                if(it->first >= p.first){  //数不低于p的个数，数够了之后该循环推出
                    i++;
                }
                it++;
            }
            result.insert(it,p);
        }
        return result;
    }
};