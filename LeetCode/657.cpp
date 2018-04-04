/* *题目：
 *  657
 *  Judge Route Circle
 * *思路：
 *  
 * *技法：
 *  
 */



class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> cnt(4,0);
        
        for(auto ch : moves){
            switch(ch){
                case 'U':cnt[0]++;break;
                case 'D':cnt[1]++;break;
                case 'L':cnt[2]++;break;
                case 'R':cnt[3]++;break;
            }
        }
        
        if(cnt[0]!=cnt[1] || cnt[2]!=cnt[3]){
            return false;
        }
        
        return true;
    }
};