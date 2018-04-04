/* *题目：
 *  栈的压入、弹出序列
 */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        stack<int> d;
        for(int i = 0, j = 0; i < pushV.size();){
            d.push(pushV[i++]);
            while(j < popV.size() && d.top() == popV[j]){
                d.pop();
                j++;
            }
        }
        
        return d.empty();
    }
};