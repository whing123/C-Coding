/* *题目：
 *  575
 *  Distribute Candies
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> kinds;
        
        int half_size = candies.size() / 2;
        for(int i = 0; i < candies.size(); ++i){
            kinds.insert(candies[i]);
            
            if(kinds.size() >= half_size){
                return half_size;
            }
        }
        
        return kinds.size();
    }
};
